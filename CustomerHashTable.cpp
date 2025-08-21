//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Implement a hash table to look up customers, add and remove customers.
// Has a vector bucket to hold customers by their ID number has keys and names/last
// names as values. Can insert, find, remove and hash
// ---------------------------------------------------------------------------
//

#include "CustomerHashTable.h"
#include <sstream>
#include <iostream>

CustomerHashTable::CustomerHashTable(size_t capacity)
    : table(capacity) {}

bool CustomerHashTable::insert(Customer* customer) {
    int key = customer->getID();
    size_t idx = hash(key);
    for (auto& c : table[idx]) {
        if (c->getID() == key) return false; // already exists
    }
    table[idx].push_back(customer);
    return true;
}

Customer* CustomerHashTable::find(int id) {
    size_t idx = hash(id);
    for (auto& c : table[idx]) {
        if (c->getID() == id) return c;
    }
    return nullptr;
}

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

void CustomerHashTable::insertFromLine(const std::string& line) {
    if (line.empty()) return;
    std::istringstream iss(line);
    int id;
    std::string last, first;
    iss >> id >> last >> first;
    Customer* cust = new Customer(id, last, first);
    insert(cust);
}

size_t CustomerHashTable::hash(int key) const {
    return key % table.size();
}

void CustomerHashTable::printCustomers() const {
    for (const auto& bucket : table) {
        for (const auto& customer : bucket) {
            customer->displayCustomer();
        }
    }
}