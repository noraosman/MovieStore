//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Returns a movie(inventory +1). Inherits from transaction class
// customer ID followed by type of media (currently only ‘D’ for
// DVD) then movie type and movie data (with values of the two sorting attributes, using
// comma or space to separate them as in the movie data file). Fields are separated by a
// space.
// ---------------------------------------------------------------------------
//

#include "Transaction.h"

#ifndef RETURN_H
#define RETURN_H

class Return : Transaction {
public:
void executeTransaction();      // Creates and bundles a new transaction if all data is correct.

private:
int custID;                     // Renting customer's ID number.
char mediaID;                   // Rented title's type, i.e comedy.
string movieName;               // Name of the rented title.
int timeStamp;                  // Time the title was rented.
};

#endif RETURN_H
