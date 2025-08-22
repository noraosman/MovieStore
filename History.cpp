
//
// ---------------------------------------------------------------------------
// Assignment 4: MovieStore
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// --------------------------------------------------------------------------
// Transaction that shows the history of a customer
// stores the customer id, prints their past transactions
// --------------------------------------------------------------------------
//


#include "History.h"
#include <sstream>
#include <iostream>

// Read customer ID from the transaction data
bool History::processData(const std::string& data) {
    std::istringstream iss(data);
    char transType;
    iss >> transType >> customerID;
    return true;
}

// Print the transaction history for the given customer
void History::execute(Store& store, CustomerHashTable& customers) {
    Customer* customer = customers.find(customerID);
    if (!customer) {
        std::cerr << "Error: Customer " << customerID << " not found.\n";
        return;
    }
    customer->printHistory();
}
