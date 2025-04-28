#pragma once
#include "NegativeQuantityException.hpp"
#include "InsufficientStockException.hpp"

class Inventory {
private:
    int stock;
public:
    Inventory(int initial_stock) : stock(initial_stock) {}

    int get_stock() const { return stock; }

    void add_items(int quantity) {
        if (quantity < 0)
            throw NegativeQuantityException();
        stock += quantity;
    }

    void remove_items(int quantity) {
        if (quantity > stock)
            throw InsufficientStockException();
        stock -= quantity;
    }
};
