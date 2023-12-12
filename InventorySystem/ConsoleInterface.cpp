#include "ConsoleInterface.h"
#include <iostream>
#include <iomanip>

using namespace std;

ConsoleInterface::ConsoleInterface(InventoryService& service) : inventoryService(service) {}

void ConsoleInterface::run() {
	while (true) {
		displayMenu();
		processUserInput();
	}
}

void ConsoleInterface::displayMenu() {
	cout << "Inventory Management System\n";
	cout << "1. Search Items\n";
	cout << "2. Add Item\n";
	cout << "3. Update Item\n";
	cout << "4. Delete Item\n";
	cout << "5. List All Items\n";
	cout << "6. Exit\n";
	cout << "Enter your choice: ";
}

void ConsoleInterface::displaySearchMenu() {
	cout << "Search by:\n";
	cout << "1. ID\n";
	cout << "2. Name\n";
	cout << "3. Quantity Greater Than\n";
	cout << "4. Quantity Less Than\n";
	cout << "5. Supplier\n";
	cout << "Enter your choice: ";
}

void ConsoleInterface::searchItems() {
	displaySearchMenu();
	int choice;
	cin >> choice;

	//Clear input buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (choice) {
	case 1: {
		int id = validateIntInput("Enter ID: ",
			"Invalid input. Please enter a valid integer for ID: ",
			[](int val) { return val >= 0; });

		Item foundItem;
		if (inventoryService.getItemById(id, foundItem)) {

			//Create a vector with the single found item
			vector<Item> items = { foundItem };

			//Display the found item
			listItems(items);
		}
		else {
			cout << "No item found with ID " << id << ".\n";
		}
		break;
	}
	case 2: {
		//Search by name
		cout << "Enter name: ";
		string name;
		getline(cin, name);
		
		//Create a vector with the items
		vector<Item> items = inventoryService.getItemsByName(name);

		//Display the found items
		listItems(items);
		break;
	}
	case 3: {
		//Search by quantity greater than
		int quantity = validateIntInput("Enter minimum quantity: ",
			"Invalid input. Please enter a valid integer for quantity: ",
			[](int val) { return val >= 0; });

		vector<Item> items = inventoryService.getItemsByQuantityGreater(quantity);
		listItems(items);
		break;
	}
	case 4: {
		//Search by quantity less than
		int quantity = validateIntInput("Enter maximum quantity: ",
			"Invalid input. Please enter a valid integer for quantity: ",
			[](int val) { return val >= 0; });

		vector<Item> items = inventoryService.getItemsByQuantityLess(quantity);
		listItems(items);
		break;
	}
	case 5: {
		//Search by supplier
		cout << "Enter supplier name: ";
		string supplier;
		getline(cin, supplier);

		vector<Item> items = inventoryService.getItemsBySupplier(supplier);
		listItems(items);
		break;
	}
	default:
		cout << "Invalid choice.\n";
		break;
	}
}

void ConsoleInterface::processUserInput() {
	int choice;
	if (!(cin >> choice)) {
		cin.clear();

		//Ignore incorrect input
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		cout << "Invalid input. Please enter a number.\n";
		return;
	}

	switch (choice) {
	case 1:
		searchItems();
		break;
	case 2:
		addItem();
		break;
	case 3:
		updateItem();
		break;
	case 4:
		deleteItem();
		break;
	case 5:
		getAllItems();
		break;
	case 6:
		exit(0);
	default:
		cout << "Invalid choice. Please try again.\n";
	}
}

void ConsoleInterface::addItem() {
	int id;
	Item tempItem;
	bool itemExists;

	do {
		id = validateIntInput("Enter Item ID (non-negative integer): ",
			"Invalid input. Please enter a non-negative integer for ID: ",
			[](int val) { return val >= 0; });

		//Check if the item id already exists
		itemExists = inventoryService.getItemById(id, tempItem);

		if (itemExists) {
			cout << "An item with the same ID already exists. Please enter a different ID.\n";
		}
	} while (itemExists);

	string name = validateStringInput("Enter Item Name (non-empty): ",
		"Invalid input. Name cannot be empty. Enter Item Name: ",
		[](const string& val) { return !val.empty(); });

	int quantity = validateIntInput("Enter Quantity (non-negative integer): ",
		"Invalid input. Please enter a non-negative integer for Quantity: ",
		[](int val) { return val >= 0; });

	double price = validateIntInput("Enter Price (non-negative number): ",
		"Invalid input. Please enter a non-negative number for Price: ",
		[](int val) { return val >= 0; });

	string supplier = validateStringInput("Enter Supplier Name (non-empty): ",
		"Invalid input. Supplier name cannot be empty. Enter Supplier Name: ",
		[](const string& val) { return !val.empty(); });

	//Create item object
	Item newItem(id, name, quantity, price, supplier);
	inventoryService.addItem(newItem);

	cout << "Item added successfully.\n";
}

void ConsoleInterface::updateItem() {
	//Enter id for the Item
	int id = validateIntInput("Enter the ID of the item to update: ",
		"Invalid input. Please enter a valid integer for ID: ",
		[](int val) { return val >= 0; });

	Item currentItem;
	if (!inventoryService.getItemById(id, currentItem)) {
		cout << "No item found with ID " << id << ".\n";
		return;
	}

	cout << "Enter new details for the item:\n";

	//Clear input buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//Enter new values for the item
	cout << "Current Name: " << currentItem.getName() << "\nEnter New Name (press Enter to keep current): ";
	string name;
	getline(cin, name);
	if (name.empty()) {
		name = currentItem.getName();
	}

	cout << "Current Quantity: " << currentItem.getQuantity() << "\nEnter New Quantity (press Enter to keep current): ";
	string quantityStr;
	getline(cin, quantityStr);
	int quantity = quantityStr.empty() ? currentItem.getQuantity() : stoi(quantityStr);

	cout << "Current Price: " << currentItem.getPrice() << "\nEnter New Price (press Enter to keep current): ";
	string priceStr;
	getline(cin, priceStr);
	double price = priceStr.empty() ? currentItem.getPrice() : stod(priceStr);

	cout << "Current Supplier: " << currentItem.getSupplier() << "\nEnter New Supplier (press Enter to keep current): ";
	string supplier;
	getline(cin, supplier);
	if (supplier.empty()) {
		supplier = currentItem.getSupplier();
	}

	//Save the Item
	Item updatedItem(id, name.empty() ? currentItem.getName() : name,
		quantity, price,
		supplier.empty() ? currentItem.getSupplier() : supplier);
	inventoryService.updateItem(id, updatedItem);

	//Message to the user
	cout << "Item with ID " << id << " has been updated.\n";
}

void ConsoleInterface::deleteItem() {
	//Prompt the user for the item id
	int id = validateIntInput("Enter the ID of the item to delete: ",
		"Invalid input. Please enter a valid integer for ID: ",
		[](int val) { return val >= 0; });

	Item tempItem;
	//Check if the item with the given id exists
	bool itemExists = inventoryService.getItemById(id, tempItem);

	if (itemExists) {
		//If the item exists delete it
		inventoryService.deleteItem(id);
		cout << "Item with ID " << id << " has been successfully deleted.\n";
	}
	else {
		//If the item does not exist inform the user
		cout << "No item found with ID " << id << ".\n";
	}
}

void ConsoleInterface::getAllItems() {
	vector<Item> items = inventoryService.getAllItems();
	listItems(items);
}

void ConsoleInterface::listItems(const vector<Item>& items) {

	if (items.empty()) {
		cout << "No items in inventory.\n";
		return;
	}

	//Display the header
	cout << left << setw(10) << "ID"
		<< setw(20) << "Name"
		<< setw(15) << "Quantity"
		<< setw(10) << "Price"
		<< setw(25) << "Supplier" << "\n";

	//Print a line for better readability
	cout << string(80, '-') << "\n";

	//Iterate and display each item
	for (const auto& item : items) {
		cout << left
			<< setw(10) << item.getId()
			<< setw(20) << item.getName()
			<< setw(15) << item.getQuantity()
			<< setw(10) << item.getPrice()
			<< setw(25) << item.getSupplier() << "\n";
	}
}

int ConsoleInterface::validateIntInput(const string& prompt, const string& errorMessage, bool condition(int)) {
	int input;
	cout << prompt;
	while (!(cin >> input) || !condition(input)) {
		//Display error message and clear input stream if input is invalid or doesn't meet the condition
		cout << errorMessage;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return input; //Return the valid input
}

string ConsoleInterface::validateStringInput(const string& prompt, const string& errorMessage, bool condition(const string&)) {
	string input;
	cout << prompt;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, input);
	while (!condition(input)) {
		//If the input doesn't meet the condition display error message and prompt for input again
		cout << errorMessage;
		getline(cin, input);
	}
	return input; //Return the valid input
}

