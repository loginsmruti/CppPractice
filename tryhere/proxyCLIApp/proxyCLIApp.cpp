#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> 
{
public:
    Session(tcp::socket socket, boost::asio::io_context& io_context, const std::string& target_address, short target_port)
        : socket_(std::move(socket)), 
            io_context_(io_context),
            target_endpoint_(boost::asio::ip::make_address(target_address), target_port),
            target_socket_(io_context) 
            {}

    void start() 
    {
        do_connect();
    }

private:
    void do_connect() {
        target_socket_.async_connect(target_endpoint_, [self = shared_from_this()](boost::system::error_code ec) {
            if (!ec) {
                self->do_read();
            }
        });
    }

    void do_read() {
        auto self(shared_from_this());
        socket_.async_read_some(boost::asio::buffer(data_, max_length),
            [this, self](boost::system::error_code ec, std::size_t length) {
                if (!ec) {
                    do_write(length);
                }
            });
    }

    void do_write(std::size_t length) {
        auto self(shared_from_this());
        boost::asio::async_write(target_socket_, boost::asio::buffer(data_, length),
            [this, self](boost::system::error_code ec, std::size_t /*length*/) {
                if (!ec) {
                    do_read();
                }
            });
    }

    tcp::socket socket_;
    boost::asio::io_context& io_context_;
    tcp::endpoint target_endpoint_;
    tcp::socket target_socket_;
    enum { max_length = 8192 };
    char data_[max_length];
};


class Proxy {
public:
    Proxy(boost::asio::io_context& io_context, short listen_port, const std::string& target_address, short target_port)
        : io_context_(io_context), 
        acceptor_(io_context, 
        tcp::endpoint(tcp::v4(), listen_port)),
        target_address_(target_address), 
        target_port_(target_port) 
    {
        do_accept();
    }

private:
    void do_accept() {
        acceptor_.async_accept([this](boost::system::error_code ec, tcp::socket socket) 
        {
            if (!ec) 
            {
                std::make_shared<Session>(std::move(socket), io_context_, target_address_, target_port_)->start();
            }
            do_accept();
        });
    }

    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_;
    std::string target_address_;
    short target_port_;
};


int main(int argc, char* argv[]) {
    try {
        if (argc != 4) {
            std::cerr << "Usage: ./proxy <listen_port> <target_address> <target_port>\n";
            return 1;
        }

        boost::asio::io_context io_context;

        Proxy proxy(io_context, std::atoi(argv[1]), argv[2], std::atoi(argv[3]));

        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
