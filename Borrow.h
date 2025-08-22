//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
//Borrow transaction. Inherits from Transaction.
// Reads customer ID, media type, genre and movie info.
// Can decrease stock and update customer history
// ---------------------------------------------------------------------------
//

#ifndef BORROW_H
#define BORROW_H

#include "Transaction.h"

class Borrow : public Transaction {
public:
    //Read data and exract fields for borrow transaction
    bool processData(const std::string& data) override;

    //Borrow the movie from store and update customer
    void execute(Store& store, CustomerHashTable& customers) override;
private:
    int customerID;
    char genre;
    std::string title, director, majorActor;
    int year, month;
};

#endif
