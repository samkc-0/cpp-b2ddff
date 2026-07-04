#include "stage01/exercises.hpp"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace stage01 {

bool operator==(const Order& left, const Order& right) {
    return left.id == right.id &&
        left.side == right.side &&
        left.price == right.price &&
        left.quantity == right.quantity;
}

bool operator==(const PriceLevel& left, const PriceLevel& right) {
    return left.price == right.price && left.orders == right.orders;
}

bool operator==(const Trade& left, const Trade& right) {
    return left.price == right.price &&
        left.quantity == right.quantity &&
        left.aggressor_order_id == right.aggressor_order_id &&
        left.resting_order_id == right.resting_order_id;
}

}  // namespace stage01

namespace {

struct TestCase {
    std::string name;
    void (*run)();
};

template <typename T>
std::string to_string_value(const T& value) {
    std::ostringstream out;
    out << value;
    return out.str();
}

std::string to_string_value(const stage01::Side& value) {
    switch (value) {
        case stage01::Side::Buy:
            return "Side::Buy";
        case stage01::Side::Sell:
            return "Side::Sell";
    }
    return "Side::<unknown>";
}

std::string to_string_value(const stage01::Order& order) {
    std::ostringstream out;
    out << "{id: " << order.id
        << ", side: " << to_string_value(order.side)
        << ", price: " << order.price
        << ", quantity: " << order.quantity
        << "}";
    return out.str();
}

template <typename T>
std::string to_string_value(const std::vector<T>& values) {
    std::ostringstream out;
    out << "{";
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            out << ", ";
        }
        out << to_string_value(values[i]);
    }
    out << "}";
    return out.str();
}

std::string to_string_value(const stage01::PriceLevel& level) {
    std::ostringstream out;
    out << "{price: " << level.price << ", orders: " << to_string_value(level.orders) << "}";
    return out.str();
}

std::string to_string_value(const stage01::Trade& trade) {
    std::ostringstream out;
    out << "{price: " << trade.price
        << ", quantity: " << trade.quantity
        << ", aggressor_order_id: " << trade.aggressor_order_id
        << ", resting_order_id: " << trade.resting_order_id
        << "}";
    return out.str();
}

template <typename T>
std::string to_string_value(const std::optional<T>& value) {
    if (!value.has_value()) {
        return "nullopt";
    }
    return "optional(" + to_string_value(*value) + ")";
}

template <typename A, typename B>
std::string to_string_value(const std::pair<A, B>& value) {
    return "(" + to_string_value(value.first) + ", " + to_string_value(value.second) + ")";
}

void require_true(bool condition, const std::string& message) {
    if (!condition) {
        throw std::runtime_error(message);
    }
}

template <typename Actual, typename Expected>
void require_equal(const Actual& actual, const Expected& expected, const std::string& context) {
    if (!(actual == expected)) {
        throw std::runtime_error(
            context + "\n  expected: " + to_string_value(expected) +
            "\n  actual:   " + to_string_value(actual)
        );
    }
}

void ex01() {
    require_equal(stage01::add(2, 3), 5, "adds positive numbers");
    require_equal(stage01::add(-4, 10), 6, "adds mixed signs");
}

void ex02() {
    require_equal(stage01::ticks_between(100, 105), stage01::Price{5}, "counts price ticks");
    require_equal(stage01::ticks_between(10025, 10100), stage01::Price{75}, "works with cent-style integer prices");
}

void ex03() {
    require_true(stage01::is_buy(stage01::Side::Buy), "buy side is buy");
    require_true(!stage01::is_buy(stage01::Side::Sell), "sell side is not buy");
}

void ex04() {
    require_equal(stage01::describe_side(stage01::Side::Buy), std::string{"buy"}, "describes buy side");
    require_equal(stage01::describe_side(stage01::Side::Sell), std::string{"sell"}, "describes sell side");
}

void ex05() {
    require_equal(stage01::opposite_side(stage01::Side::Buy), stage01::Side::Sell, "opposite of buy is sell");
    require_equal(stage01::opposite_side(stage01::Side::Sell), stage01::Side::Buy, "opposite of sell is buy");
}

void ex06() {
    require_true(stage01::is_valid_price(100), "positive price is valid");
    require_true(!stage01::is_valid_price(0), "zero price is invalid");
    require_true(!stage01::is_valid_price(-1), "negative price is invalid");
}

void ex07() {
    require_true(stage01::is_valid_quantity(10), "non-zero quantity is valid");
    require_true(!stage01::is_valid_quantity(0), "zero quantity is invalid");
}

void ex08() {
    require_true(stage01::is_valid_order({1, stage01::Side::Buy, 100, 10}), "valid order passes");
    require_true(!stage01::is_valid_order({2, stage01::Side::Buy, 0, 10}), "zero price fails");
    require_true(!stage01::is_valid_order({3, stage01::Side::Sell, 100, 0}), "zero quantity fails");
}

void ex09() {
    require_equal(
        stage01::sum_quantities({{1, stage01::Side::Buy, 100, 10}, {2, stage01::Side::Sell, 101, 5}}),
        stage01::Quantity{15},
        "sums quantities"
    );
    require_equal(stage01::sum_quantities({}), stage01::Quantity{0}, "empty input sums to 0");
}

void ex10() {
    require_equal(
        stage01::count_orders_on_side(
            {{1, stage01::Side::Buy, 100, 10}, {2, stage01::Side::Sell, 101, 5}, {3, stage01::Side::Buy, 99, 2}},
            stage01::Side::Buy
        ),
        2,
        "counts buy orders"
    );
}

void ex11() {
    require_equal(
        stage01::order_ids({{10, stage01::Side::Buy, 100, 1}, {11, stage01::Side::Sell, 101, 2}}),
        std::vector<stage01::OrderId>{10, 11},
        "returns IDs in FIFO order"
    );
}

void ex12() {
    stage01::Order order{1, stage01::Side::Sell, 100, 10};
    require_equal(stage01::fill_order(order, 4), stage01::Quantity{4}, "fills requested quantity");
    require_equal(order.quantity, stage01::Quantity{6}, "reduces order quantity");
    require_equal(stage01::fill_order(order, 99), stage01::Quantity{6}, "cannot fill more than remains");
    require_equal(order.quantity, stage01::Quantity{0}, "fully filled order reaches zero");
}

void ex13() {
    require_true(stage01::is_crossing(stage01::Side::Buy, 101, 100), "buy crosses lower ask");
    require_true(stage01::is_crossing(stage01::Side::Buy, 100, 100), "buy crosses equal ask");
    require_true(!stage01::is_crossing(stage01::Side::Buy, 99, 100), "buy does not cross higher ask");
    require_true(stage01::is_crossing(stage01::Side::Sell, 99, 100), "sell crosses higher bid");
    require_true(!stage01::is_crossing(stage01::Side::Sell, 101, 100), "sell does not cross lower bid");
}

void ex14() {
    require_equal(
        stage01::price_level_quantity({100, {{1, stage01::Side::Sell, 100, 7}, {2, stage01::Side::Sell, 100, 3}}}),
        stage01::Quantity{10},
        "sums quantity at a price level"
    );
}

void ex15() {
    require_true(stage01::has_orders({100, {{1, stage01::Side::Buy, 100, 2}}}), "level with order has orders");
    require_true(!stage01::has_orders({100, {}}), "empty level has no orders");
}

void ex16() {
    const std::vector<stage01::Order> orders{{1, stage01::Side::Buy, 100, 2}, {2, stage01::Side::Sell, 101, 4}};
    require_equal(
        stage01::find_order(orders, 2),
        std::optional<stage01::Order>{{2, stage01::Side::Sell, 101, 4}},
        "finds order by id"
    );
    require_equal(stage01::find_order(orders, 9), std::optional<stage01::Order>{}, "missing id returns nullopt");
}

void ex17() {
    const std::vector<stage01::Order> orders{{1, stage01::Side::Buy, 100, 2}, {2, stage01::Side::Sell, 101, 4}};
    require_true(stage01::contains_order_id(orders, 1), "contains present id");
    require_true(!stage01::contains_order_id(orders, 8), "does not contain absent id");
}

void ex18() {
    std::vector<stage01::Order> orders{{1, stage01::Side::Buy, 100, 2}, {2, stage01::Side::Sell, 101, 4}};
    require_true(stage01::cancel_order(orders, 1), "cancel returns true when removed");
    require_equal(orders, std::vector<stage01::Order>{{2, stage01::Side::Sell, 101, 4}}, "removes matching order");
    require_true(!stage01::cancel_order(orders, 9), "unknown cancel returns false");
}

void ex19() {
    require_equal(
        stage01::orders_at_price(
            {{1, stage01::Side::Buy, 100, 2}, {2, stage01::Side::Buy, 101, 4}, {3, stage01::Side::Buy, 100, 5}},
            100
        ),
        std::vector<stage01::Order>{{1, stage01::Side::Buy, 100, 2}, {3, stage01::Side::Buy, 100, 5}},
        "filters orders at requested price"
    );
}

void ex20() {
    require_equal(stage01::best_bid({100, 103, 99}), std::optional<stage01::Price>{103}, "highest bid wins");
    require_equal(stage01::best_bid({}), std::optional<stage01::Price>{}, "no bids returns nullopt");
}

void ex21() {
    require_equal(stage01::best_ask({100, 103, 99}), std::optional<stage01::Price>{99}, "lowest ask wins");
    require_equal(stage01::best_ask({}), std::optional<stage01::Price>{}, "no asks returns nullopt");
}

void ex22() {
    require_equal(
        stage01::make_price_level(
            100,
            {{1, stage01::Side::Sell, 100, 2}, {2, stage01::Side::Sell, 101, 4}, {3, stage01::Side::Sell, 100, 0}}
        ),
        stage01::PriceLevel{100, {{1, stage01::Side::Sell, 100, 2}}},
        "keeps only valid orders at the requested price"
    );
}

void ex23() {
    stage01::PriceLevel level{100, {{1, stage01::Side::Buy, 100, 2}}};
    require_true(stage01::append_order(level, {2, stage01::Side::Buy, 100, 3}), "appends matching valid order");
    require_equal(
        level.orders,
        std::vector<stage01::Order>{{1, stage01::Side::Buy, 100, 2}, {2, stage01::Side::Buy, 100, 3}},
        "preserves FIFO order"
    );
    require_true(!stage01::append_order(level, {3, stage01::Side::Buy, 101, 3}), "rejects different price");
}

void ex24() {
    stage01::PriceLevel level{
        100,
        {{1, stage01::Side::Sell, 100, 0}, {2, stage01::Side::Sell, 100, 0}, {3, stage01::Side::Sell, 100, 5}}
    };
    stage01::remove_filled_front_orders(level);
    require_equal(level.orders, std::vector<stage01::Order>{{3, stage01::Side::Sell, 100, 5}}, "removes filled front orders");
}

void ex25() {
    stage01::Order incoming{7, stage01::Side::Buy, 101, 8};
    stage01::Order resting{3, stage01::Side::Sell, 100, 5};
    require_equal(
        stage01::match_quantity(incoming, resting),
        stage01::Trade{100, 5, 7, 3},
        "returns trade at resting price"
    );
    require_equal(incoming.quantity, stage01::Quantity{3}, "reduces incoming quantity");
    require_equal(resting.quantity, stage01::Quantity{0}, "reduces resting quantity");
}

void ex26() {
    require_equal(
        stage01::remaining_order_if_any({1, stage01::Side::Buy, 100, 4}),
        std::optional<stage01::Order>{{1, stage01::Side::Buy, 100, 4}},
        "remaining order is returned"
    );
    require_equal(
        stage01::remaining_order_if_any({2, stage01::Side::Sell, 100, 0}),
        std::optional<stage01::Order>{},
        "filled order returns nullopt"
    );
}

void ex27() {
    require_true(stage01::would_rest_after_matching({1, stage01::Side::Buy, 100, 10}, 6), "some quantity remains");
    require_true(!stage01::would_rest_after_matching({1, stage01::Side::Buy, 100, 10}, 10), "exact fill leaves nothing");
    require_true(!stage01::would_rest_after_matching({1, stage01::Side::Buy, 100, 10}, 12), "over-fill leaves nothing");
}

void ex28() {
    require_equal(
        stage01::format_price_level(stage01::Side::Buy, {100, {{1, stage01::Side::Buy, 100, 7}, {2, stage01::Side::Buy, 100, 3}}}),
        std::string{"BID 100 x 10"},
        "formats bid level"
    );
    require_equal(
        stage01::format_price_level(stage01::Side::Sell, {101, {{3, stage01::Side::Sell, 101, 4}}}),
        std::string{"ASK 101 x 4"},
        "formats ask level"
    );
}

void ex29() {
    require_equal(
        stage01::price_quantity_pair({100, {{1, stage01::Side::Buy, 100, 7}, {2, stage01::Side::Buy, 100, 3}}}),
        std::pair<stage01::Price, stage01::Quantity>{100, 10},
        "returns price and aggregate quantity"
    );
}

void ex30() {
    require_equal(
        stage01::low_quantity_order_ids(
            {{1, stage01::Side::Buy, 100, 2}, {2, stage01::Side::Buy, 100, 10}, {3, stage01::Side::Sell, 101, 1}},
            5
        ),
        std::vector<stage01::OrderId>{1, 3},
        "returns low-quantity order ids in order"
    );
}

const std::vector<TestCase>& tests() {
    static const std::vector<TestCase> all{
        {"ex01", ex01}, {"ex02", ex02}, {"ex03", ex03}, {"ex04", ex04}, {"ex05", ex05},
        {"ex06", ex06}, {"ex07", ex07}, {"ex08", ex08}, {"ex09", ex09}, {"ex10", ex10},
        {"ex11", ex11}, {"ex12", ex12}, {"ex13", ex13}, {"ex14", ex14}, {"ex15", ex15},
        {"ex16", ex16}, {"ex17", ex17}, {"ex18", ex18}, {"ex19", ex19}, {"ex20", ex20},
        {"ex21", ex21}, {"ex22", ex22}, {"ex23", ex23}, {"ex24", ex24}, {"ex25", ex25},
        {"ex26", ex26}, {"ex27", ex27}, {"ex28", ex28}, {"ex29", ex29}, {"ex30", ex30},
    };
    return all;
}

bool matches_filter(const std::string& name, const std::string& filter) {
    return filter.empty() || name.rfind(filter, 0) == 0;
}

}  // namespace

int main(int argc, char** argv) {
    const std::string filter = argc > 1 ? argv[1] : "";
    int passed = 0;
    int failed = 0;
    int selected = 0;

    for (const auto& test : tests()) {
        if (!matches_filter(test.name, filter)) {
            continue;
        }

        ++selected;
        try {
            test.run();
            ++passed;
            std::cout << "[PASS] " << test.name << "\n";
        } catch (const std::exception& error) {
            ++failed;
            std::cout << "[FAIL] " << test.name << "\n" << error.what() << "\n";
        }
    }

    if (selected == 0) {
        std::cerr << "No tests matched filter '" << filter << "'. Try ex01, ex14, or no filter.\n";
        return EXIT_FAILURE;
    }

    std::cout << "\n" << passed << " passed, " << failed << " failed, " << selected << " selected\n";
    return failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
