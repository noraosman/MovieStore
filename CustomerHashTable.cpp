//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Implement a hash table to look up, add and remove  and load customers.
// ---------------------------------------------------------------------------
//

#include "CustomerHashTable.h"
#include <sstream>
#include <iostream>

// Creates a hashtable with given number of buckets
CustomerHashTable::CustomerHashTable(size_t capacity)
    : table(capacity) {}

CustomerHashTable::~CustomerHashTable() {
    for (auto& bucket : table) {
        for (auto& customer : bucket) {
            delete customer;
        }
    }
}

//Insert  a customer into the table, return true if successful,
// return false if it already exists
bool CustomerHashTable::insert(Customer* customer) {
    int key = customer->getID();
    size_t idx = hash(key);
    for (auto& c : table[idx]) {
        if (c->getID() == key) return false; // already exists
    }
    table[idx].push_back(customer);
    return true;
}

//Find a customer by the ID, return the customer if found
// return nullptr if not found
Customer* CustomerHashTable::find(int id) {
    size_t idx = hash(id);
    for (auto& c : table[idx]) {
        if (c->getID() == id) return c;
    }
    return nullptr;
}


//Remove customer by ID, return true if removed
// return false if unsuccesful
bool CustomerHashTable::remove(int id) {
    size_t idx = hash(id);
    for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
        if ((*it)->getID() == id) {
            table[idx].erase(it);
            return true;
        }
    }
    return false;
}

// Build a customer from a life of text and insert into a table
void CustomerHashTable::insertFromLine(const std::string& line) {
    if (line.empty()) return;
    std::istringstream iss(line);
    int id;
    std::string last, first;
    iss >> id >> last >> first;
    Customer* cust = new Customer(id, last, first);
    insert(cust);
}

//Hash function, maps customer ID into a bucket
size_t CustomerHashTable::hash(int key) const {
    return key % table.size();
}


// Print all customer in the table
void CustomerHashTable::printCustomers() const {
    for (const auto& bucket : table) {
        for (const auto& customer : bucket) {
            customer->displayCustomer();
        }
    }
}