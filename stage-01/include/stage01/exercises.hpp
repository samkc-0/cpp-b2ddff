#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace stage01 {

using OrderId = std::uint64_t;
using Price = std::int64_t;
using Quantity = std::uint64_t;

enum class Side {
    Buy,
    Sell,
};

struct Order {
    OrderId id;
    Side side;
    Price price;
    Quantity quantity;
};

struct PriceLevel {
    Price price;
    std::vector<Order> orders;
};

struct Trade {
    Price price;
    Quantity quantity;
    OrderId aggressor_order_id;
    OrderId resting_order_id;
};

int add(int left, int right);
Price ticks_between(Price lower_price, Price higher_price);
bool is_buy(Side side);
std::string describe_side(Side side);
Side opposite_side(Side side);
bool is_valid_price(Price price);
bool is_valid_quantity(Quantity quantity);
bool is_valid_order(const Order& order);
Quantity sum_quantities(const std::vector<Order>& orders);
int count_orders_on_side(const std::vector<Order>& orders, Side side);
std::vector<OrderId> order_ids(const std::vector<Order>& orders);
Quantity fill_order(Order& order, Quantity requested_quantity);
bool is_crossing(Side incoming_side, Price incoming_price, Price resting_price);
Quantity price_level_quantity(const PriceLevel& level);
bool has_orders(const PriceLevel& level);
std::optional<Order> find_order(const std::vector<Order>& orders, OrderId id);
bool contains_order_id(const std::vector<Order>& orders, OrderId id);
bool cancel_order(std::vector<Order>& orders, OrderId id);
std::vector<Order> orders_at_price(const std::vector<Order>& orders, Price price);
std::optional<Price> best_bid(const std::vector<Price>& bid_prices);
std::optional<Price> best_ask(const std::vector<Price>& ask_prices);
PriceLevel make_price_level(Price price, const std::vector<Order>& orders);
bool append_order(PriceLevel& level, const Order& order);
void remove_filled_front_orders(PriceLevel& level);
Trade match_quantity(Order& incoming, Order& resting);
std::optional<Order> remaining_order_if_any(const Order& order);
bool would_rest_after_matching(const Order& incoming, Quantity matched_quantity);
std::string format_price_level(Side side, const PriceLevel& level);
std::pair<Price, Quantity> price_quantity_pair(const PriceLevel& level);
std::vector<OrderId> low_quantity_order_ids(const std::vector<Order>& orders, Quantity threshold);

}  // namespace stage01
