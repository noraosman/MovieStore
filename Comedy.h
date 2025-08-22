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

#ifndef COMEDY_H
#define COMEDY_H

#include "Movie.h"
#include "MovieFactory.h"

class Comedy : public Movie {
public:
    Comedy() = default; // Default constructor
    Comedy(std::string);
    bool operator<(const Movie& other) const override; // Finished
    bool operator==(const Movie& other) const override; // Finished
    void display(); // Finished
    void processData(std::string) override; // Finished
    int getStock() const;
    void decrementStock();
    void incrementStock();
private:
};
#endif

