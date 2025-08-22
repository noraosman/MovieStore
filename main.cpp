#include <iostream>
#include <fstream>
#include "Store.h"
#include "CustomerHashTable.h"
#include "TransactionFactory.h"

using namespace std;

int main() {
    Store store;
    CustomerHashTable customers;
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
    movieFile.close();
    /////////////////////////////////////////

    // Load customers
    ifstream customerFile("data4customers.txt");
    if (!customerFile) {
        cerr << "Error opening customer data file." << endl;
        return 1;
    }
    
    while (getline(customerFile, line)) {
        if (line.empty()) {
            continue;
        } else {
            customers.insertFromLine(line);
        }
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
        if (line.empty()) {
            continue;
        } else {
            Transaction* transaction = nullptr;
            char code = line[0];
            switch (code) {
                case 'B':
                    transaction = TransactionFactory::createTrans(TransactionFactory::TransactionType::Borrow);
                    break;
                case 'I':
                    transaction = TransactionFactory::createTrans(TransactionFactory::TransactionType::Show);
                    break;
                case 'R':
                    transaction = TransactionFactory::createTrans(TransactionFactory::TransactionType::ReturnItem);
                    break;
                case 'H':
                    transaction = TransactionFactory::createTrans(TransactionFactory::TransactionType::History);
                    break;
                default:
                    cerr << "Unknown transaction type: " << code << endl;
                    continue;
            }
            if (transaction) {
                if (transaction->processData(line)) {
                    transaction->execute(store, customers);
                }
                delete transaction;
            }
        }
    }
    commandFile.close();
    /////////////////////////////////////////

    return 0;
}
