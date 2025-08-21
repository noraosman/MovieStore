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
Customer(int, std::string, std::string);
int getID() const;
void displayCustomer() const;

private:
int id;                             // Customer's ID, as provided in the transactions.
string first;                        // Customer's first name, as provided in the transactions.
string last;                         // Customer's last name, as provided in the transactions.
};

#endif
