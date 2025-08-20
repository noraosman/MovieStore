//
// ---------------------------------------------------------------------------
// Assignment 4: MovieFactory
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Inherits attributes from Inventory aka Movie class.
// ---------------------------------------------------------------------------
//

#include "Comedy.h"
#include <iostream>
#include <sstream>

Comedy::Comedy(std::string data) {
    processData(data);
}

void Comedy::processData(std::string data) {
    // Remove the leading 'F,' if present
    if (data[0] == 'F') {
        data = data.substr(2); // Skip "F,"
    } else {
        std::cerr << "Error: Invalid data format for Comedy movie." << std::endl;
        return;
    }

    std::istringstream iss(data);
    std::string stockStr, directorStr, titleStr;
    int yearVal;

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

bool Comedy::operator<(const Movie& other) const {
    const Comedy* otherComedy = dynamic_cast<const Comedy*>(&other);
    if (!otherComedy) {
        std::cerr << "Error: Attempted to compare Comedy with non-Comedy Movie in Comedy::operator<." << std::endl;
        return false;
    }

    // First, compare by title
    if (title != otherComedy->title)
        return title < otherComedy->title;

    // Then, compare by year released
    return year < otherComedy->year;
}

bool Comedy::operator==(const Movie& other) const {
    const Comedy* otherComedy = dynamic_cast<const Comedy*>(&other);
    if (!otherComedy) {
        std::cerr << "Error: Attempted to compare Comedy with non-Comedy Movie in Comedy::operator==." << std::endl;
        return false;
    }

    // Compare director, title, and year for equality
    return (director == otherComedy->director &&
            title == otherComedy->title &&
            year == otherComedy->year);
}

void Comedy::display() {
    std::cout << stock << ", " << director << ", " << title << ", " << year << std::endl;
}
