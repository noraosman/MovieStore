#include <iostream>
#include <fstream>
#include "Store.h"

using namespace std;

int main() {
    Store store;

    // Load movies
    ifstream movieFile("data4movies.txt");
    if (!movieFile) {
        cerr << "Error opening movie data file." << endl;
        return 1;
    }
    /////////////////////////////////////////
    // Logic to read movie data and populate the inventory
    /////////////////////////////////////////

    movieFile.close();
    // Load customers
    ifstream customerFile("data4customers.txt");
    if (!customerFile) {
        cerr << "Error opening customer data file." << endl;
        return 1;
    }
    /////////////////////////////////////////
    // Logic to read customer data and populate the customers hash table
    /////////////////////////////////////////

    customerFile.close();
    // Process commands
    ifstream commandFile("data4commands.txt");
    if (!commandFile) {
        cerr << "Error opening command data file." << endl;
        return 1;
    }
    //////////////////////////////////////////
    // Logic to read commands and perform transactions
    //////////////////////////////////////////

    commandFile.close();
    return 0;
}