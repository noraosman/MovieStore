cmake_minimum_required(VERSION 3.31)
project(MovieStore)

set(CMAKE_CXX_STANDARD 20)

add_executable(MovieStore main.cpp
        MovieStore.h
        MovieStore.cpp
        "MovieFactory .h"
        MovieFactory.cpp
        Movie.h
        Inventory.cpp
        Comedy.h
        Comedy.cpp
        Drama.h
        Drama.cpp
        Classic.h
        Classic.cpp
        Customer.h
        Customer.cpp
        "TransactionFactory .h"
        Transaction.cpp
        Transaction.h
        Transaction.cpp
        Borrow.h
        Borrow.cpp
        Return.h
        Return.cpp
        History.h
        History.cpp
        Inventory.h
        Inventory.cpp
        HashTable.H.cpp
        HashTable.h)
