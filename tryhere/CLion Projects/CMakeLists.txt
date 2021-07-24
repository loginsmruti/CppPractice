cmake_minimum_required(VERSION 3.15)
project(CLion_Projects)

set(CMAKE_CXX_STANDARD 11)

set(Boost_INCLUDE_DIR /usr/local/Cellar/boost/1.72.0_1/include/)
set(Boost_LIBRARY_DIR /usr/local/Cellar/boost/1.72.0_1/lib/)
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(CLion_Projects vectorAPI.cpp)

target_link_libraries( CLion_Projects ${Boost_LIBRARIES} )



