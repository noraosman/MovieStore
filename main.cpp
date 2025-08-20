#include <iostream>
#include <fstream>
#include "Store.h"

using namespace std;

int main() {
    Store store;
    string line;

    // Load movies
    ifstream movieFile("data4movies.txt");
    if (!movieFile) {
        cerr << "Error opening movie data file." << endl;
        return 1;
    }
    
    while (getline(movieFile, line)) {
        if (line.empty()) {
            continue; 
        } else if (line[0] == 'C' || line[0] == 'D' || line[0] == 'F') {
            store.loadMovie(line);
        } else {
            cerr << "Unknown movie type: " << line[0] << endl;
            continue; // Skip unknown types
        }
    }

    store.printInventory();
    movieFile.close();
    /////////////////////////////////////////

    /*
    // Load customers
    ifstream customerFile("data4customers.txt");
    if (!customerFile) {
        cerr << "Error opening customer data file." << endl;
        return 1;
    }
    
    while (getline(customerFile, line)) {
        if (line.empty()) continue; // Skip empty lines

        // Parse the line to create a Customer object
        // Example: "123, John Doe, 555-1234"
        // Logic to parse and create a customer object and add it to the hash table
    }
    customerFile.close();
    /////////////////////////////////////////

    // Process commands
    ifstream commandFile("data4commands.txt");
    if (!commandFile) {
        cerr << "Error opening command data file." << endl;
        return 1;
    }
    
    while (getline(commandFile, line)) {
        if (line.empty()) continue; // Skip empty lines

        // Parse the command line
        // Example: "B 123 D Comedy, Funny Movie, 2020"
        // Logic to parse the command and perform the corresponding transaction
        // using TransactionFactory to create the appropriate transaction object
    }
    commandFile.close();
    /////////////////////////////////////////
    */

    return 0;
}
