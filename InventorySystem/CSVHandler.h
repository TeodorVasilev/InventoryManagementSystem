#pragma once
#include "Item.h"
#include <vector>
#include <string>

class CSVHandler {
public:
    // Method to append an item to the CSV file
    void appendItemToCSV(const Item& item, const std::string& filename);

    // Method to read form CSV file
    std::vector<Item> readItemsFromCSV(const std::string& filename);

    //Method to write the updated list of items to CSV file
    void writeItemsToCSV(const std::vector<Item>& items, const std::string& filename);
};
