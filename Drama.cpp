//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Inherits attributes from Inventory aka Movie class
// Has comparison, display and stock management functions
// ---------------------------------------------------------------------------
//
#include "Drama.h"
#include <iostream>
#include <sstream>


// Constructor builds a drama movie from data string
Drama::Drama(std::string data) {
    processData(data);
}

// Process a data string and fill in Drama movie attributes
void Drama::processData(std::string data) {
    // Remove the leading 'D,' if present
    if (data[0] == 'D') {
        data = data.substr(2);
        data.erase(0, data.find_first_not_of(' '));
    } else {
        std::cerr << "Error: Invalid data format for Drama movie." << std::endl;
        return;
    }

    std::istringstream iss(data);
    std::string stockStr, directorStr, titleStr, yearStr;

    // Parse stock
    std::getline(iss, stockStr, ',');
    stock = std::stoi(stockStr);

    // Parse director
    std::getline(iss, directorStr, ',');
    directorStr.erase(0, directorStr.find_first_not_of(' '));
    directorStr.erase(directorStr.find_last_not_of(' ') + 1);
    director = directorStr;

    // Parse title
    std::getline(iss, titleStr, ',');
    titleStr.erase(0, titleStr.find_first_not_of(' '));
    titleStr.erase(titleStr.find_last_not_of(' ') + 1);
    title = titleStr;

    // Parse year
    iss >> year;
}

// Compare two drama mobies by director and then by title
bool Drama::operator<(const Movie& other) const {
    const Drama* otherDrama = dynamic_cast<const Drama*>(&other);
    if (!otherDrama) {
        std::cerr << "Error: Attempted to compare Drama with non-Drama Movie in Drama::operator<." << std::endl;
        return false;
    }

    // First, compare by director
    if (director != otherDrama->director)
        return director < otherDrama->director;

    // Then, compare by title
    return title < otherDrama->title;
}

//Equality check, director, title adn year must match
bool Drama::operator==(const Movie& other) const {
    const Drama* otherDrama = dynamic_cast<const Drama*>(&other);
    if (!otherDrama) {
        std::cerr << "Error: Attempted to compare Drama with non-Drama Movie in Drama::operator==." << std::endl;
        return false;
    }

    // Compare director, title, and year for equality
    return (director == otherDrama->director &&
            title == otherDrama->title &&
            year == otherDrama->year);
}

// Print drama movie details
void Drama::display() const {
    std::cout << stock << ", " << director << ", " << title << ", " << year << std::endl;
}

//Stock access and updates
int Drama::getStock() const { return stock; }
void Drama::decrementStock() { if (stock > 0) --stock; }
void Drama::incrementStock() { ++stock; }