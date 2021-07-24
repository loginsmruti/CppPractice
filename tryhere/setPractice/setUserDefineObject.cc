#include<iostream>
#include<set>

class Message 
{
  public:
    std::string sentBy;
    std::string msg;
    std::string recvBy;
    
    Message(std::string msgSent, std::string msgString , std::string msgRecvd)
      : sentBy(msgSent) , msg(msgString) , recvBy(msgRecvd)
    { }
    
    bool operator<(const Message& message) const {
      
      std::string str1 = message.sentBy + message.msg+ message.recvBy;
      std::string str2 = this->sentBy + this->msg + this->recvBy;

      return str1 < str2; 
    }

    friend std::ostream& operator<<(std::ostream& os , const Message& obj) {
      os << "Sent By : " << obj.sentBy << " Message : " << obj.msg << " Received By : " << obj.recvBy << std:: endl;

      return os;
    }
};

int main()
{

  Message msg1("user_1", "Hello", "user_2");
  Message msg2("user_1", "Hello", "user_3");
  Message msg3("user_3", "Hello", "user_1");
  Message msg4("user_1", "Hello", "user_3");
  
  std::set<Message> numbers;

  numbers.insert(msg1);
  numbers.insert(msg2);
  numbers.insert(msg3);
  numbers.insert(msg4);

     

  return 0;
}
