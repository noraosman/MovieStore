//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// has hash table of customers for easy lookup and inventory of the movies
// can load and find movies, load and find customers, print inventory and start
// a transaction.
// ---------------------------------------------------------------------------
//


#ifndef STORE_H
#define STORE_H

#include "Movie.h"
#include <string>
#include "Inventory.h"

class Store{
private:
    //HashTable customers;        //Stores customers keyed by ID
    Inventory inventory;        //Stores and manages movie collection

public:
    // Constructor & Destructor
    Store() = default;
    //~Store();

    // load Data
    void loadMovie(std::string);
    void loadCustomers();

    // Search Data
    //Movie* findMovie(const std::string& movieKey);
    //Customer* findCustomer(int customerID);

    // prints inventory
    void printInventory();

    // starts a transaction
    void startTransaction();
};


#endif
