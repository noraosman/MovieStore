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

#include "Customer.h"
#include <iostream>
#include "Movie.h"

//Creates a customer with ID, last name and first name
Customer::Customer(int id, std::string last, std::string first) {
    this->id = id;
    this->last = last;
    this->first = first;
}

//Returns customer ID
int Customer::getID() const {
    return id;
}

//Prints customer info
void Customer::displayCustomer() const {
    std::cout << "Customer ID: " << id << ", Name: " << first << " " << last << std::endl;  
}

//Adds a record to history
void Customer::addHistory(const std::string& record) {
    history.push_back(record);
}

//Prints all transaction history
void Customer::printHistory() const {
    std::cout << "History for customer " << id << ":\n";
    for (const auto& rec : history) {
        std::cout << rec << std::endl;
    }
    std::cout << std::endl;
}

//Adds a movie to borrowed list
void Customer::addBorrowedMovie(Movie* movie) {
    borrowedMovies.push_back(movie);
}

//Removes a movie from borrowed list
void Customer::removeBorrowedMovie(Movie* movie) {
    for (auto it = borrowedMovies.begin(); it != borrowedMovies.end(); ++it) {
        if (*it == movie) {
            borrowedMovies.erase(it);
            return;
        }
    }
}


//Checks if a movie is in borrowed list
bool Customer::hasBorrowedMovie(Movie* movie) const {
    for (const auto& m : borrowedMovies) {
        if (m == movie) return true;
    }
    return false;
}