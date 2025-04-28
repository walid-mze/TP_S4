#include <iostream>
#include "Inventory.hpp"
#include "NegativeQuantityException.hpp"
#include "InsufficientStockException.hpp"

int main() {
    Inventory inv(100);
    std::cout << "Initial stock: " << inv.get_stock() << std::endl;

    try {
        inv.add_items(50);
        std::cout << "After adding 50 items: " << inv.get_stock() << std::endl;
    }
    catch (const NegativeQuantityException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    try {
        inv.remove_items(160);
        std::cout << "After removing 160 items: " << inv.get_stock() << std::endl;
    }
    catch (const InsufficientStockException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    try {
        inv.add_items(-10);
        std::cout << "After adding -10 items: " << inv.get_stock() << std::endl;
    }
    catch (const NegativeQuantityException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    std::cout << "Program completed" << std::endl;
    return 0;
}
