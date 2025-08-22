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

#ifndef CLASSIC_H
#define CLASSIC_H

#include <string>
#include "Movie.h"
#include "MovieFactory.h"

class Classic : public Movie {
public:
    Classic() = default; // Default constructor
    Classic(std::string);

    //Comparison
    bool operator<(const Movie& other) const override;
    bool operator==(const Movie& other) const override;

    //Prints movie info
    void display();

    //Parse data string
    void processData(std::string) override;

    //Specific identifying attributes for Classic
    int getReleaseMonth() const { return releaseMonth; }
    const std::string& getMajorActorName() const { return majorActorName; }

    //Stock management
    int getStock() const;
    void decrementStock();
    void incrementStock();
protected:
    std::string majorActorName; // Major actor's name
    int releaseMonth; // Release month
};
#endif
