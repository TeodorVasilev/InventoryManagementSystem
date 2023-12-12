#include "ConsoleInterface.h"
#include "InventoryService.h"

int main() {
    InventoryService inventoryService;
    ConsoleInterface consoleInterface(inventoryService);
    consoleInterface.run();

    return 0;
}
