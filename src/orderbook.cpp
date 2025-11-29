#include "orderbook.hpp"
#include <iostream>

void OrderBook::addOrder(const Order& order) {
    if (order.isBuyOrder) {
        buyOrders[order.price].push(order);
    } else {
        sellOrders[order.price].push(order);
    }
}

void OrderBook::matchOrders() {
    while (!buyOrders.empty() && !sellOrders.empty()) {
        auto& bestBuy = buyOrders.begin()->second;
        auto& bestSell = sellOrders.begin()->second;
        auto buyPrice = buyOrders.begin()->first;
        auto sellPrice = sellOrders.begin()->first;

        if (buyPrice >= sellPrice) {
            int tradeQuantity = std::min(bestBuy.front().quantity, bestSell.front().quantity);
            std::cout << "Trade executed: " << tradeQuantity << " @ " << sellPrice << "\n";

            bestBuy.front().quantity -= tradeQuantity;
            bestSell.front().quantity -= tradeQuantity;

            if(bestBuy.front().quantity == 0) bestBuy.pop();
            if(bestSell.front().quantity == 0) bestSell.pop();

            if(bestBuy.empty()) buyOrders.erase(buyPrice);
            if(bestSell.empty()) sellOrders.erase(sellPrice);

        } else break;
    }
}