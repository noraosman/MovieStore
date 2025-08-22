//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Returns a movie(inventory +1). Inherits from transaction class
// customer ID followed by type of media (currently only ‘D’ for
// DVD) then movie type and movie data (with values of the two sorting attributes, using
// comma or space to separate them as in the movie data file). Fields are separated by a
// space.
// ---------------------------------------------------------------------------
//

#include "ReturnItem.h"
#include <sstream>
#include <iostream>


// ---------------------------------------------------------------------------
// Parses a line of transaction data into ReturnItem fields.
// Finds customer ID by media type and genre
// Depending on genre, parses movie by identifying attributes
// Returns true if successful, false for invalid data
// ---------------------------------------------------------------------------
bool ReturnItem::processData(const std::string& data) {
    std::istringstream iss(data);
    char transType, mediaType;
    iss >> transType >> customerID >> mediaType >> genre;

	// Parse based on genre
    if (genre == 'F') {
		// Comedy: Title, Year
        std::getline(iss, title, ',');      // read until sees comma
        iss >> year;
        title.erase(0, title.find_first_not_of(' '));
    } else if (genre == 'D') {
		// Drama: Director, Title
        std::getline(iss, director, ',');
        std::getline(iss, title, ',');
        director.erase(0, director.find_first_not_of(' '));
        title.erase(0, title.find_first_not_of(' '));
    } else if (genre == 'C') {
		// Classic: Month, Year, Major Actor
        iss >> month >> year;
        std::string first, last;
        iss >> first >> last;
        majorActor = first + " " + last;   // Combine into full name
    } else {
        return false;
    }
    return true;
}

// ---------------------------------------------------------------------------
// Executes the return transaction
// Looks up the customer by ID in hash table
// Calls thr store and returns based on genre
// If successful, increments stock and logs the transaction in customers history
// ---------------------------------------------------------------------------
void ReturnItem::execute(Store& store, CustomerHashTable& customers) {
    Customer* customer = customers.find(customerID);
    if (!customer) {
        std::cerr << "Error: Customer " << customerID << " not found.\n";
        return;
    }
    bool success = false;
    if (genre == 'F') {
        success = store.returnComedy(title, year, customer);
    } else if (genre == 'D') {
        success = store.returnDrama(director, title, customer);
    } else if (genre == 'C') {
        success = store.returnClassic(year, month, majorActor, customer);
    }
    if (success) {
        customer->addHistory("Returned: " + std::string(1, genre) + " " + title);
    }
}
