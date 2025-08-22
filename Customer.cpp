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

#include "Customer.h"
#include <iostream>
#include "Movie.h"

Customer::Customer(int id, std::string last, std::string first) {
    this->id = id;
    this->last = last;
    this->first = first;
}

int Customer::getID() const {
    return id;
}

void Customer::displayCustomer() const {
    std::cout << "Customer ID: " << id << ", Name: " << first << " " << last << std::endl;  
}

void Customer::addHistory(const std::string& record) {
    history.push_back(record);
}
void Customer::printHistory() const {
    std::cout << "History for customer " << id << ":\n";
    for (const auto& rec : history) {
        std::cout << rec << std::endl;
    }
}

void Customer::addBorrowedMovie(Movie* movie) {
    borrowedMovies.push_back(movie);
}

void Customer::removeBorrowedMovie(Movie* movie) {
    for (auto it = borrowedMovies.begin(); it != borrowedMovies.end(); ++it) {
        if (*it == movie) {
            borrowedMovies.erase(it);
            return;
        }
    }
}

bool Customer::hasBorrowedMovie(Movie* movie) const {
    for (const auto& m : borrowedMovies) {
        if (m == movie) return true;
    }
    return false;
}