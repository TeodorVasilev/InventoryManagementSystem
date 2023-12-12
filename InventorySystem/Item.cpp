#include "Item.h"

Item::Item()
    : id(0), quantity(0), price(0.0) {
}

Item::Item(int id, const std::string& name, int quantity, double price, const std::string& supplier)
    : id(id), name(name), quantity(quantity), price(price), supplier(supplier) {
}

int Item::getId() const {
    return id;
}

const std::string& Item::getName() const {
    return name;
}

int Item::getQuantity() const {
    return quantity;
}

double Item::getPrice() const {
    return price;
}

const std::string& Item::getSupplier() const {
    return supplier;
}