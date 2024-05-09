cmake_minimum_required(VERSION 3.10)
project(ProxyCLIApp)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS system)

add_executable(proxyCLIApp proxyCLIApp.cpp)
target_link_libraries(proxyCLIApp PRIVATE Boost::boost Boost::system)
