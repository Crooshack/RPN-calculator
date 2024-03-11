cmake_minimum_required(VERSION 3.27)
project(Project_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Project_1 main.cpp
        functions.cpp
        myStack/myStack.cpp
        myStack/myStackNode.cpp
        myList/myList.cpp
        myList/myListNode.cpp)
