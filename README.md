# Inventory Management System Documentation

## Getting Started

To start using the Inventory Management System, follow these steps:

1. **Download the Project**:
   - Navigate to the GitHub repository.
   - Click on the `Code` button and download the ZIP file of the project, or clone the repository using Git.

2. **Extract and Navigate to Release Folder**:
   - Extract the downloaded ZIP file to your preferred location.
   - Navigate to the `Release` folder within the extracted files.

3. **Run the Application**:
   - In the `Release` folder, find the `InventorySystem.exe` file.
   - Double-click `InventorySystem.exe` to start the application.
   

## Overview

The Inventory Management System is a console-based application developed in C++, designed to manage an inventory of items. The system allows users to add, update, delete, and search for items in the inventory. All data is stored in a CSV file, enabling persistent storage and retrieval of inventory data.

## Functionalities

### 1. Adding an Item
- **Functionality**: Allows the user to add a new item to the inventory.
- **Usage**:
  - Select the option to add an item.
  - Enter the details of the item, including ID, name, quantity, price, and supplier.

### 2. Updating an Item
- **Functionality**: Enables updating the details of an existing item in the inventory.
- **Usage**:
  - Select the option to update an item.
  - Enter the ID of the item to be updated.
  - Enter the new details for the item. Leave fields blank to retain current values.

### 3. Deleting an Item
- **Functionality**: Allows the deletion of an item from the inventory.
- **Usage**:
  - Select the option to delete an item.
  - Enter the ID of the item to be deleted.

### 4. Searching for Items
- **Functionality**: Provides various search criteria to locate items in the inventory.
- **Usage**:
  - Select the option to search for items.
  - Choose the search criterion (by ID, name, quantity, or supplier).
  - Enter the corresponding search value.

### 5. Listing All Items
- **Functionality**: Displays all items currently in the inventory.
- **Usage**:
  - Select the option to list all items.

### 6. Exiting the Program
- **Functionality**: Exits the inventory management system.
- **Usage**:
  - Select the option to exit the program.

## Instructions for Use

1. **Starting the Application**:
   - Run the executable to start the inventory management system.

2. **Navigating the Menu**:
   - Upon starting, the main menu is displayed with options to search, add, update, delete, list items, and exit.
   - Use the keyboard to enter the number corresponding to the desired action.

3. **Performing Actions**:
   - Follow the on-screen prompts to enter the necessary information for each action.
   - For search operations, choose the appropriate criterion and provide the search value.

4. **Viewing Results**:
   - After each operation, the results (such as the list of items or a confirmation message) will be displayed on the screen.

5. **Exiting the Application**:
   - To exit the application, choose the exit option from the main menu.

## Data Storage

- The system stores item data in a CSV file named `inventory.csv`.
- Each item's details, including ID, name, quantity, price, and supplier, are stored in this file.
