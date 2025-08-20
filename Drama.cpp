//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Inherits attributes from Inventory aka Movie class.
// ---------------------------------------------------------------------------
//

#include "Drama.h"
#include <iostream>

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