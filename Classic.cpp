//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Inherits attributes from Inventory aka Movie class.
// Adds major actor and release month fields, parsing, comparison
// display and stock management
// ---------------------------------------------------------------------------
//

#include "Classic.h"
#include <iostream>
#include <sstream>
 //Constructor builds a classic movie from data string
Classic::Classic(std::string data) {
    processData(data);
}

//Parse data string and fill classic attributes
void Classic::processData(std::string data) {
    // Remove the leading 'C,' if present
    if (data[0] == 'C') {
        data = data.substr(2); // Skip "C,"
    } else {
        std::cerr << "Error: Invalid data format for Classic movie." << std::endl;
        return;
    }

    std::istringstream iss(data);
    std::string stockStr, directorStr, titleStr, actorFirst, actorLast;
    int monthVal, yearVal;

    // Parse stock
    std::getline(iss, stockStr, ',');
    stock = std::stoi(stockStr);

    // Parse director
    std::getline(iss, directorStr, ',');
    // Remove leading/trailing spaces
    directorStr.erase(0, directorStr.find_first_not_of(' '));
    directorStr.erase(directorStr.find_last_not_of(' ') + 1);
    director = directorStr;

    // Parse title
    std::getline(iss, titleStr, ',');
    titleStr.erase(0, titleStr.find_first_not_of(' '));
    titleStr.erase(titleStr.find_last_not_of(' ') + 1);
    title = titleStr;

    // Parse major actor (first and last name), month, year
    iss >> actorFirst >> actorLast >> monthVal >> yearVal;
    majorActorName = actorFirst + " " + actorLast;
    releaseMonth = monthVal;
    year = yearVal;
}


//Compare classics by year, then month and then actor
bool Classic::operator<(const Movie& other) const {
    // Attempt to cast other to Classic
    const Classic* otherClassic = dynamic_cast<const Classic*>(&other);
    if (!otherClassic) {
        std::cerr << 
        "Error: Attempted to compare Classic with non-Classic Movie in Classic::operator<." 
        << std::endl;
        return false;
    }

    // First, compare by release year
    if (year != otherClassic->year)
        return year < otherClassic->year;

    // Then, compare by release month
    if (releaseMonth != otherClassic->releaseMonth)
        return releaseMonth < otherClassic->releaseMonth;

    // Finally, compare by major actor's name
    return majorActorName < otherClassic->majorActorName;
}

//Equality check, all fields must match
bool Classic::operator==(const Movie& other) const {
    // Attempt to cast other to Classic
    const Classic* otherClassic = dynamic_cast<const Classic*>(&other);
    if (!otherClassic) {
        std::cerr << 
        "Error: Attempted to compare Classic with non-Classic Movie in Classic::operator==." 
        << std::endl;
        return false;
    }

    // Compare all attributes for equality
    return (director == otherClassic->director &&
        title == otherClassic->title &&
        year == otherClassic->year &&
        releaseMonth == otherClassic->releaseMonth &&
        majorActorName == otherClassic->majorActorName);
}

//Print classic movie details
void Classic::display() {
    std::cout << stock << ", " << director << ", " << title << ", "
              << majorActorName << " " << releaseMonth << " " << year
              << std::endl;
}

//Update and access stock
int Classic::getStock() const { return stock; }
void Classic::decrementStock() { if (stock > 0) --stock; }
void Classic::incrementStock() { ++stock; }