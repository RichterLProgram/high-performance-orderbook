#include "orderbook.hpp"
#include "matching_engine.hpp"

int main() {
    OrderBook book;
    MatchingEngine engine;

    Order order1 = {1, 100.0, 10, true}; // Buy order
    Order order2 = {2, 99.0, 5, false}; // Sell order

    engine.processOrder(book, order1);
    engine.processOrder(book, order2);

    return 0;
}