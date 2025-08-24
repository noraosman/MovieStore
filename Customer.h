//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Stores customer info by ID and Name. Tracks borrowed movies and transaction history.
// ---------------------------------------------------------------------------
//

#include <string>
#include <vector>
#include "Movie.h"

using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
public:
    //Creates customer with ID, last name and first name
    Customer(int, std::string, std::string);

    // Get customer ID
    int getID() const;

    //Print customer info
    void displayCustomer() const;

    //Add a transaction to record the history
    void addHistory(const std::string& record);

    //Print all transaction history
    void printHistory() const;

    // Track borrowed movies
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
