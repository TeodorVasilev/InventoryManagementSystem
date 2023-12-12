#include "InventoryService.h"
#include "CSVHandler.h"

using namespace std;

InventoryService::InventoryService() {
}

void InventoryService::addItem(const Item& item) {
    CSVHandler csvHandler;
    const string filename = "inventory.csv"; //Define the CSV file name

    //Append the item to the CSV file
    csvHandler.appendItemToCSV(item, filename);
}

void InventoryService::updateItem(int id, const Item& updatedItem) {
    CSVHandler csvHandler;
    const string filename = "inventory.csv";
    vector<Item> items = csvHandler.readItemsFromCSV(filename);
    vector<Item> updatedItems;

    for (const Item& currentItem : items) {
        if (currentItem.getId() == id) {
            //Replace with the updated item
            updatedItems.push_back(updatedItem);
        }
        else {
            //Retain the current item
            updatedItems.push_back(currentItem);
        }
    }

    //Write the updated list of items back to the CSV file
    csvHandler.writeItemsToCSV(updatedItems, filename);
}

void InventoryService::deleteItem(int id) {
    CSVHandler csvHandler;
    const string filename = "inventory.csv";
    vector<Item> items = csvHandler.readItemsFromCSV(filename);
    vector<Item> updatedItems;

    //Filter out the item to be deleted
    for (const Item& item : items) {
        if (item.getId() != id) {
            updatedItems.push_back(item);
        }
    }

    //Write the updated list back to the CSV file
    csvHandler.writeItemsToCSV(updatedItems, filename);
}

vector<Item> InventoryService::getAllItems() const {
    CSVHandler csvHandler;
    const string filename = "inventory.csv";

    //Read and return all items from the CSV file
    return csvHandler.readItemsFromCSV(filename);
}

vector<Item> InventoryService::getItemsByName(const string& name) const {
    CSVHandler csvHandler;
    const string filename = "inventory.csv";
    vector<Item> allItems = csvHandler.readItemsFromCSV(filename);
    vector<Item> filteredItems;

    //Add Items with a matching name to the list
    for (const auto& item : allItems) {
        if (item.getName() == name) {
            filteredItems.push_back(item);
        }
    }

    return filteredItems;
}

vector<Item> InventoryService::getItemsByQuantityGreater(int quantity) const {
    CSVHandler csvHandler;
    const string filename = "inventory.csv";
    vector<Item> allItems = csvHandler.readItemsFromCSV(filename);
    vector<Item> filteredItems;

    //Add items whose quantity is greater than the specified amount
    for (const auto& item : allItems) {
        if (item.getQuantity() > quantity) {
            filteredItems.push_back(item);
        }
    }

    return filteredItems;
}

vector<Item> InventoryService::getItemsByQuantityLess(int quantity) const {
    CSVHandler csvHandler;
    const string filename = "inventory.csv";
    vector<Item> allItems = csvHandler.readItemsFromCSV(filename);
    vector<Item> filteredItems;

    //Add items whose quantity is less than the specified amount
    for (const auto& item : allItems) {
        if (item.getQuantity() < quantity) {
            filteredItems.push_back(item);
        }
    }

    return filteredItems;
}

vector<Item> InventoryService::getItemsBySupplier(const string& supplier) const {
    CSVHandler csvHandler;
    const string filename = "inventory.csv";
    vector<Item> allItems = csvHandler.readItemsFromCSV(filename);
    vector<Item> filteredItems;

    //Add items with a supplier matching name to the list
    for (const auto& item : allItems) {
        if (item.getSupplier() == supplier) {
            filteredItems.push_back(item);
        }
    }

    return filteredItems;
}

bool InventoryService::getItemById(int id, Item& outItem) const {
    CSVHandler csvHandler;
    const string filename = "inventory.csv";
    vector<Item> items = csvHandler.readItemsFromCSV(filename);

    for (const Item& item : items) {
        if (item.getId() == id) {

            // Set the outItem to the found item
            outItem = item;

            return true;
        }
    }

    // Item not found
    return false;
}