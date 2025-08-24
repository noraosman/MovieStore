//
// ---------------------------------------------------------------------------
// Assignment 4: MovieStore
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Comedy movie class, inherits from Movie. Adds comparison, display
// and stock management functions
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

    // Comparison operators
    bool operator<(const Movie& other) const override;
    bool operator==(const Movie& other) const override;

    // Prints movie info
    void display() const override;

    // Processes input data
    void processData(std::string) override;

    //Stock management
    int getStock() const;
    void decrementStock();
    void incrementStock();
private:
};
#endif

