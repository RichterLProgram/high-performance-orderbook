#include "orderbook.hpp"

class MatchingEngine {
    public:
        void processOrder(OrderBook& book, const Order& order);
};