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

#ifndef HISTORY_H
#define HISTORY_H

#include "Transaction.h"

class History : public Transaction {
public:
    // Reads and stores the customer ID from input
    bool processData(const std::string& data) override;

    // Finds the customer and prints their history
    void execute(Store& store, CustomerHashTable& customers) override;
private:
    int customerID;
};

#endif