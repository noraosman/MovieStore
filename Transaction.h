
//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Uses transactionFactory to create a new transaction based on customer ID, media D for (DVD)
// and movieName
// ---------------------------------------------------------------------------
//

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "Store.h"
#include "CustomerHashTable.h"

class Transaction {
public:
virtual ~Transaction() = default; // Virtual destructor for proper cleanup of derived classes
virtual void execute(Store& store, CustomerHashTable& customers) = 0;
virtual bool processData(const std::string& data) = 0;

private:
};


#endif
