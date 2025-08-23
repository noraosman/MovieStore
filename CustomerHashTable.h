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
#ifndef CUSTOMERHASHTABLE_H
#define CUSTOMERHASHTABLE_H

#include <vector>
#include <list>
#include <string>
#include "Customer.h"

class CustomerHashTable {
public:
    // creats hash table with given capacity(default size = 101 buckets)
    CustomerHashTable(size_t capacity = 101);
    ~CustomerHashTable();

    // Add customer to the table
    bool insert(Customer* customer);

    // Find customer by ID
    Customer* find(int id);

    // Remove customer by ID
    bool remove(int id);

    //Insert customer by reading data from a line
    void insertFromLine(const std::string& line);

    // Print all customers
    void printCustomers() const;

private:
    // Table of buckets. each bucket is list of customers
    std::vector<std::list<Customer*>> table;

    // Hash function: turns ID into bucket index
    size_t hash(int key) const;
};

#endif
