//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Stores customer info by ID and Name. Customer has transaction history.
// ---------------------------------------------------------------------------
//

#include "Customer.h"
#include <iostream>

Customer::Customer(int id, std::string last, std::string first) {
    this->id = id;
    this->last = last;
    this->first = first;
}

int Customer::getID() const {
    return id;
}

void Customer::displayCustomer() const {
    std::cout << "Customer ID: " << id << ", Name: " << first << " " << last << std::endl;  
}