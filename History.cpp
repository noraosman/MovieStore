#include "History.h"
#include <sstream>
#include <iostream>

bool History::processData(const std::string& data) {
    std::istringstream iss(data);
    char transType;
    iss >> transType >> customerID;
    return true;
}

void History::execute(Store& store, CustomerHashTable& customers) {
    Customer* customer = customers.find(customerID);
    if (!customer) {
        std::cerr << "Error: Customer " << customerID << " not found.\n";
        return;
    }
    customer->printHistory();
}
