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
#include <vector>
#include "Movie.h"

using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
public:
    Customer(int, std::string, std::string);
    int getID() const;
    void displayCustomer() const;
    void addHistory(const std::string& record);
    void printHistory() const;
    void addBorrowedMovie(Movie* movie);
    void removeBorrowedMovie(Movie* movie);
    bool hasBorrowedMovie(Movie* movie) const;

private:
    std::vector<Movie*> borrowedMovies;
    std::vector<std::string> history;
    int id;                             // Customer's ID, as provided in the transactions.
    string first;                        // Customer's first name, as provided in the transactions.
    string last;                         // Customer's last name, as provided in the transactions.
};

#endif
