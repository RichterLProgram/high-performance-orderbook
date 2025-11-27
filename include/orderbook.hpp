#include <map>
#include <queue>

struct Order {
    int id;
    double price;
    int quantity;
    bool isBuyOrder;
};

class OrderBook {
    public:
        void addOrder(const Order& order);
        void matchOrders();
    private:
        std::map<double, std::queue<Order>, std::greater<>> buyOrders> buyOrders;
        std::map<double, std::queue<Order>> sellOrders;
};