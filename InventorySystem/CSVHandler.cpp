#include "CSVHandler.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void CSVHandler::appendItemToCSV(const Item& item, const string& filename) {
    ofstream file;

    //Open in append mode
    file.open(filename, ios::out | ios::app);

    if (!file.is_open()) {
        throw runtime_error("Unable to open file: " + filename);
    }

    //Write the item to the file in CSV format
    file << item.getId() << ","
        << item.getName() << ","
        << item.getQuantity() << ","
        << item.getPrice() << ","
        << item.getSupplier() << "\n";

    file.close();
}

vector<Item> CSVHandler::readItemsFromCSV(const string& filename) {
    vector<Item> items;
    ifstream file(filename);

    if (!file.is_open()) {
        //If the file doesn't exist return an empty vector.
        return {};
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string field;
        vector<string> fields;

        //Split the line into fields
        while (getline(iss, field, ',')) {
            fields.push_back(field);
        }

        //Parse each field and create an item
        if (fields.size() >= 5) {
            int id = stoi(fields[0]);
            string name = fields[1];
            int quantity = stoi(fields[2]);
            double price = stod(fields[3]);
            string supplier = fields[4];

            items.push_back(Item(id, name, quantity, price, supplier));
        }
    }

    file.close();
    return items;
}

void CSVHandler::writeItemsToCSV(const vector<Item>& items, const string& filename) {
    //Open a file stream for writing using the provided filename
    ofstream file(filename);

    //Check if the file stream was successfully opened
    if (!file.is_open()) {
        throw runtime_error("Unable to open file: " + filename);
    }

    //Write the item's details to the file, separated by commas
    for (const auto& item : items) {
        file << item.getId() << ","
            << item.getName() << ","
            << item.getQuantity() << ","
            << item.getPrice() << ","
            << item.getSupplier() << "\n";
    }

    file.close();
}

