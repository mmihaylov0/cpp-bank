cmake_minimum_required(VERSION 3.21)
project(bank)

set(CMAKE_CXX_STANDARD 14)

add_executable(bank main.cpp Transaction.cpp Account.cpp Bank.cpp Bank.h Account.h Transaction.h)
