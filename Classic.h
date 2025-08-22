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

#ifndef CLASSIC_H
#define CLASSIC_H

#include <string>
#include "Movie.h"
#include "MovieFactory.h"

class Classic : public Movie {
public:
    Classic() = default; // Default constructor
    Classic(std::string);
    bool operator<(const Movie& other) const override; // Finished
    bool operator==(const Movie& other) const override; // Finished
    void display(); // Finished
    void processData(std::string) override; // Finished
    int getReleaseMonth() const { return releaseMonth; }
    const std::string& getMajorActorName() const { return majorActorName; }
    int getStock() const;
    void decrementStock();
    void incrementStock();
protected:
    std::string majorActorName; // Major actor's name
    int releaseMonth; // Release month
};
#endif
