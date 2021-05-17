cmake_minimum_required(VERSION 3.4.1)
    
# Enable C++11
set(CMAKE_CXX_STANDARD 11)

project(Leetcodec)

add_executable(Leetcodec 
               ./src/main.cpp
               ./src/SolutionFactory.cpp
               ./src/Trie.cpp)
