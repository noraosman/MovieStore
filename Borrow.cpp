//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Borrows a movie(inventory -1). Inherits from transaction class
// customer ID followed by type of media (currently only ‘D’ for
// DVD) then movie type and movie data (with values of the two sorting attributes, using
// comma or space to separate them as in the movie data file). Fields are separated by a
// space.
// ---------------------------------------------------------------------------
//

#include "Borrow.h"
#include <sstream>
#include <iostream>

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
        customer->addHistory("Borrowed: " + std::string(1, genre) + " " + title);
    }
}