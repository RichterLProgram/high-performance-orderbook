#include "matching_engine.hpp"

void MatchingEngine::processOrder(OrderBook& book, const Order& order) {
    book.addOrder(order);
    book.matchOrders();
}