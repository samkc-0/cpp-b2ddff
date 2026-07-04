#include "stage01/exercises.hpp"

namespace stage01 {

// ex01: Return the sum of left and right.
int add(int left, int right) {
    (void)left;
    (void)right;
    return 0;
}

// ex02: Return how many integer price ticks sit between lower_price and higher_price.
Price ticks_between(Price lower_price, Price higher_price) {
    (void)lower_price;
    (void)higher_price;
    return 0;
}

// ex03: Return true when side is Side::Buy.
bool is_buy(Side side) {
    (void)side;
    return false;
}

// ex04: Return "buy" for Side::Buy and "sell" for Side::Sell.
std::string describe_side(Side side) {
    (void)side;
    return "";
}

// ex05: Return Sell for Buy, and Buy for Sell.
Side opposite_side(Side side) {
    (void)side;
    return Side::Buy;
}

// ex06: Return true when price is positive.
bool is_valid_price(Price price) {
    (void)price;
    return false;
}

// ex07: Return true when quantity is greater than zero.
bool is_valid_quantity(Quantity quantity) {
    (void)quantity;
    return false;
}

// ex08: Return true when the order has a positive price and non-zero quantity.
bool is_valid_order(const Order& order) {
    (void)order;
    return false;
}

// ex09: Return the sum of all order quantities.
Quantity sum_quantities(const std::vector<Order>& orders) {
    (void)orders;
    return 0;
}

// ex10: Count how many orders are on the requested side.
int count_orders_on_side(const std::vector<Order>& orders, Side side) {
    (void)orders;
    (void)side;
    return 0;
}

// ex11: Return all order IDs in their current vector order.
std::vector<OrderId> order_ids(const std::vector<Order>& orders) {
    (void)orders;
    return {};
}

// ex12: Fill up to requested_quantity from order.quantity.
// Reduce order.quantity by the executed amount and return the executed amount.
Quantity fill_order(Order& order, Quantity requested_quantity) {
    (void)order;
    (void)requested_quantity;
    return 0;
}

// ex13: Return true if an incoming order at incoming_price can trade with a resting price.
// Buy crosses when incoming_price >= resting_price. Sell crosses when incoming_price <= resting_price.
bool is_crossing(Side incoming_side, Price incoming_price, Price resting_price) {
    (void)incoming_side;
    (void)incoming_price;
    (void)resting_price;
    return false;
}

// ex14: Return the total quantity resting at this price level.
Quantity price_level_quantity(const PriceLevel& level) {
    (void)level;
    return 0;
}

// ex15: Return true when the price level contains at least one order.
bool has_orders(const PriceLevel& level) {
    (void)level;
    return false;
}

// ex16: Return the first order with id, or std::nullopt if absent.
std::optional<Order> find_order(const std::vector<Order>& orders, OrderId id) {
    (void)orders;
    (void)id;
    return std::nullopt;
}

// ex17: Return true when an order with id appears in orders.
bool contains_order_id(const std::vector<Order>& orders, OrderId id) {
    (void)orders;
    (void)id;
    return false;
}

// ex18: Remove the first order with id. Return true if one was removed.
bool cancel_order(std::vector<Order>& orders, OrderId id) {
    (void)orders;
    (void)id;
    return false;
}

// ex19: Return all orders with the requested price, preserving their order.
std::vector<Order> orders_at_price(const std::vector<Order>& orders, Price price) {
    (void)orders;
    (void)price;
    return {};
}

// ex20: Return the highest bid price, or std::nullopt for no bids.
std::optional<Price> best_bid(const std::vector<Price>& bid_prices) {
    (void)bid_prices;
    return std::nullopt;
}

// ex21: Return the lowest ask price, or std::nullopt for no asks.
std::optional<Price> best_ask(const std::vector<Price>& ask_prices) {
    (void)ask_prices;
    return std::nullopt;
}

// ex22: Build a price level containing only valid orders at exactly price.
PriceLevel make_price_level(Price price, const std::vector<Order>& orders) {
    (void)price;
    (void)orders;
    return {};
}

// ex23: Append order to level if it is valid and its price matches level.price.
// Return true if appended.
bool append_order(PriceLevel& level, const Order& order) {
    (void)level;
    (void)order;
    return false;
}

// ex24: Remove filled orders from the front of the level until the front is not filled.
// A filled order has quantity == 0.
void remove_filled_front_orders(PriceLevel& level) {
    (void)level;
}

// ex25: Match incoming against resting.
// Execute the smaller remaining quantity, reduce both orders, and return a Trade.
// The trade price is the resting order's price.
Trade match_quantity(Order& incoming, Order& resting) {
    (void)incoming;
    (void)resting;
    return {};
}

// ex26: Return the order if it still has quantity, otherwise std::nullopt.
std::optional<Order> remaining_order_if_any(const Order& order) {
    (void)order;
    return std::nullopt;
}

// ex27: Return true when incoming.quantity is greater than matched_quantity.
bool would_rest_after_matching(const Order& incoming, Quantity matched_quantity) {
    (void)incoming;
    (void)matched_quantity;
    return false;
}

// ex28: Format a price level as "BID 100 x 12" or "ASK 100 x 12".
std::string format_price_level(Side side, const PriceLevel& level) {
    (void)side;
    (void)level;
    return "";
}

// ex29: Return {level.price, total_quantity_at_that_price}.
std::pair<Price, Quantity> price_quantity_pair(const PriceLevel& level) {
    (void)level;
    return {0, 0};
}

// ex30: Return IDs for orders whose quantity is strictly below threshold.
std::vector<OrderId> low_quantity_order_ids(const std::vector<Order>& orders, Quantity threshold) {
    (void)orders;
    (void)threshold;
    return {};
}

}  // namespace stage01
