//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Stores customer info by ID and Name. Customer has transaction history.
// ---------------------------------------------------------------------------
//

#include <string>
#include <queue>

using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
public:
void setID(int);
int getID();
void addTrans();
void getHistory();

private:
int id;                             // Customer's ID, as provided in the transactions.
string name;                        // Customer's name, as provided in the transactions.
queue<string> history;              // History of rented movies.
queue<string> currentRentals;       // Collection of currently rented titles.
};

#endif CUSTOMER_H
