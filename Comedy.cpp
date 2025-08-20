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
