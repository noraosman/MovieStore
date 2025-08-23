//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
//Borrow transaction. Inherits from Transaction.
// Reads customer ID, media type, genre and movie info.
// Can decrease stock and update customer history
// ---------------------------------------------------------------------------
//


#include "Borrow.h"
#include <sstream>
#include <iostream>

//Read data string and extract fields for borrow transactions
bool Borrow::processData(const std::string& data) {
    std::istringstream iss(data);
    char transType, mediaType;
    iss >> transType >> customerID >> mediaType >> genre;

    if (genre == 'F') { // Comedy
        std::getline(iss, title, ',');
        iss >> year;
        title.erase(0, title.find_first_not_of(' '));

    } else if (genre == 'D') { // Drama
        std::getline(iss, director, ',');
        std::getline(iss, title, ',');
        director.erase(0, director.find_first_not_of(' '));
        title.erase(0, title.find_first_not_of(' '));

    } else if (genre == 'C') { // Classic
        iss >> month >> year;
        std::string first, last;
        iss >> first >> last;
        majorActor = first + " " + last;

    } else {
        return false;
    }
    return true;
}

// Borrow the movie from store and update customer history
void Borrow::execute(Store& store, CustomerHashTable& customers) {
    Customer* customer = customers.find(customerID);
    if (!customer) {
        std::cerr << "Error: Customer " << customerID << " not found.\n";
        return;
    }
    bool success = false;
    if (genre == 'F') {
        success = store.borrowComedy(title, year, customer);
    } else if (genre == 'D') {
        success = store.borrowDrama(director, title, customer);
    } else if (genre == 'C') {
        success = store.borrowClassic(year, month, majorActor, customer);
    }

    if (success) {
    std::string movieInfo;
    if (genre == 'C') {
        Classic* movie = store.getInventory().findClassic(year, month, majorActor);
        std::string movieTitle = movie ? movie->getTitle() : "";
        movieInfo = "C " + movieTitle;
    } else {
        movieInfo = std::string(1, genre) + " " + title;
    }
    customer->addHistory("Borrowed: " + movieInfo);
}
}