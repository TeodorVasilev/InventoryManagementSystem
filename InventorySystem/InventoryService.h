#pragma once
#include "Item.h"
#include <vector>

using namespace std;

class InventoryService {
public:
    InventoryService();

    void addItem(const Item& item);
    void updateItem(int id, const Item& item);
    void deleteItem(int id);
    bool getItemById(int id, Item& outItem) const;
    vector<Item> getAllItems() const;
    vector<Item> getItemsByName(const string& name) const;
    vector<Item> getItemsByQuantityGreater(int quantity) const;
    vector<Item> getItemsByQuantityLess(int quantity) const;
    vector<Item> getItemsBySupplier(const string& supplier) const;
};


