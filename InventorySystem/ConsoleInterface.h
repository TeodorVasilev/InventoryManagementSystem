#pragma once
#include "InventoryService.h"

class ConsoleInterface {
public:
    ConsoleInterface(InventoryService& service);
    // Main loop for the interface
    void run(); 

private:
    InventoryService& inventoryService;

    void displayMenu();
    void displaySearchMenu(); 
    void processUserInput(); 

    // Methods for each CRUD operation
    void addItem();
    void updateItem();
    void deleteItem();
    void getAllItems();
    void searchItems();
    void listItems(const vector<Item>& items);

    //Validation methods
    int validateIntInput(const std::string& prompt, const std::string& errorMessage, bool condition(int));
    std::string validateStringInput(const std::string& prompt, const std::string& errorMessage, bool condition(const std::string&));
};
