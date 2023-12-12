#pragma once
#include <string>

class Item {
private:
    int id;
    std::string name;
    int quantity;
    double price;
    std::string supplier;

public:
    Item();
    Item(int id, const std::string& name, int quantity, double price, const std::string& supplier);

    int getId() const;
    const std::string& getName() const;
    int getQuantity() const;
    double getPrice() const;
    const std::string& getSupplier() const;
};

