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
#ifndef CUSTOMERHASHTABLE_H
#define CUSTOMERHASHTABLE_H

#include <vector>
#include <list>
#include <string>
#include "Customer.h"

class CustomerHashTable {
public:
    CustomerHashTable(size_t capacity = 101);

    bool insert(Customer* customer);
    Customer* find(int id);
    bool remove(int id);
    void insertFromLine(const std::string& line);
    void printCustomers() const;

private:
    std::vector<std::list<Customer*>> table;
    size_t hash(int key) const;
};

#endif
