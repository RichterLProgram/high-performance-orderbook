#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../src/orderbook.hpp"

TEST_CASE("Limit Order") {
    Orderbook orderbook;
    Order buyOrder(1, OrderType::Buy, 100, 10);
    orderbook.addOrder(buyOrder);

    REQUIRE(book.bestBid() == 100);
}