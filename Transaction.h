
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

using namespace std;

class Transaction {
public:
virtual ~Transaction() = default; // Virtual destructor for proper cleanup of derived classes

virtual void doTrans() = 0;
virtual void processData() = 0;
virtual void display() = 0;

private:
int custID;                     // Renting customer's ID number.
char mediaID;                   // Rented title's type, i.e comedy.
string movieName;               // Name of the rented title.
int timeStamp;                  // Time the title was rented.
string transType;               // Type of transaction being preformed, borrow or return.
};


#endif
