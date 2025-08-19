
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

#include <string>

using namespace std;

#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {
public:
void doTrans();
void processData();

private:
int custID;                     // Renting customer's ID number.
char mediaID;                   // Rented title's type, i.e comedy.
string movieName;               // Name of the rented title.
int timeStamp;                  // Time the title was rented.
string transType;               // Type of transaction being preformed, borrow or return.
};


#endif TRANSACTION_H
