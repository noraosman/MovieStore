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
#include "HashTable.h"
#include "Show.h"
#include "Movie.h"
#include "Customer.h"
#include <string>

class MovieStore{
private:
    HashTable customers;        //stores customers keyed by ID
    Inventory inventory;         //Stores and manages movie collection

public:
    // Constructor & Destructor
    MovieStore();
    ~MovieStore();

    // load Data
    void loadMovie();
    void loadCustomers();

    // Search Data
    Movie* findMovie(const string& movieKey);
    Customer* findCustomer(int customerID);

    // prints inventory
    void printInventory();

    // starts a transaction
    void startTransaction();


};


#endif
