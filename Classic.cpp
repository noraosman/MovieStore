//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Inherits attributes from Inventory aka Movie class.
// Displays also Major actor and release date
// ---------------------------------------------------------------------------
//

#include "Classic.h"
#include <iostream>

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

void Classic::display() {
    std::cout << stock << ", " << director << ", " << title << ", "
              << majorActorName << " " << releaseMonth << " " << year
              << std::endl;
}