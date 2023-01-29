cmake_minimum_required(VERSION 3.4)
set (CMAKE_CXX_STANDARD 11)
project(LBSEncryption)

add_library(LBSEncryptLib
LBSEncryption.h
LBSEncryption.cpp)



add_executable(LBSEncryption
main.cpp)



target_link_libraries(LBSEncryption
LBSEncryptLib)