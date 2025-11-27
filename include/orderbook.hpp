#include <map>
#include <queue>

struct Order {
    int id;
    double price;
    int quantity;
    bool isBuyOrder; // Differentiate between Buy/Sell orders
};

class OrderBook {
    public:
        void addOrder(const Order& order);
        void matchOrders(); // Match buy and sell
    private:
        // Map find best prices quickly in O(log n) time
        std::map<double, std::queue<Order>, std::greater<>> buyOrders;
        std::map<double, std::queue<Order>> sellOrders;
};