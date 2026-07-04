# Stage 01 Capstone: Toy Limit Order Book

Build a single-instrument limit order book that supports adding, matching,
canceling, and viewing orders.

This project prioritizes correctness and learning over extreme performance. It
is a good capstone because it turns simple language tools into a real stateful
system: enums, structs, functions, classes, references, const, maps, lists,
unordered maps, optionals, and clear control flow.

## Goal

The order book has two sides:

- Bid book: buy orders, where the highest price has priority.
- Ask book: sell orders, where the lowest price has priority.

Orders at the same price follow FIFO priority: first order in, first order out.

Prices and quantities should be integers, not floating point values.

```cpp
// $101.25 represented as 10125
using Price = int64_t;
using Quantity = uint64_t;
```

## Order Fields

Each order should contain:

```cpp
enum class Side {
    Buy,
    Sell,
};

using OrderId = uint64_t;
using Price = int64_t;
using Quantity = uint64_t;

struct Order {
    OrderId id;
    Side side;
    Price price;
    Quantity quantity;
};
```

## Supported Operations

### Limit Order

A limit order has:

- side
- price
- quantity
- order ID

A buy limit order can match against asks priced at or below the buy price.

A sell limit order can match against bids priced at or above the sell price.

Any unfilled quantity rests on the book.

### Cancel Order

A cancel removes an existing resting order by order ID.

Canceling an unknown order ID should fail gracefully.

## Required Public API

Implement a class like this:

```cpp
class OrderBook {
public:
    bool add_limit_order(OrderId id, Side side, Price price, Quantity quantity);
    bool cancel_order(OrderId id);

    std::optional<Price> best_bid() const;
    std::optional<Price> best_ask() const;
    Quantity quantity_at_price(Side side, Price price) const;
    bool contains_order(OrderId id) const;

    void print_book() const;
};
```

Return `false` for rejected orders and failed cancels. Return `true` for accepted
orders, even if the order immediately fully trades and does not rest on the
book.

## Matching Rules

When adding a buy order:

1. Look at the lowest ask price.
2. If the ask price is greater than the buy price, stop matching.
3. Otherwise, match against the oldest order at that ask price.
4. Reduce quantities.
5. Remove fully filled orders.
6. Continue until the incoming order is fully filled or no matching ask exists.
7. If quantity remains, add the buy order to the bid book.

When adding a sell order:

1. Look at the highest bid price.
2. If the bid price is less than the sell price, stop matching.
3. Otherwise, match against the oldest order at that bid price.
4. Reduce quantities.
5. Remove fully filled orders.
6. Continue until the incoming order is fully filled or no matching bid exists.
7. If quantity remains, add the sell order to the ask book.

## Trade Output

Whenever a match occurs, print a trade:

```text
TRADE price=10050 quantity=25 aggressor_order_id=7 resting_order_id=3
```

The trade price should be the resting order's price.

## Data Structures

Use these structures for the first version:

```cpp
#include <cstdint>
#include <functional>
#include <list>
#include <map>
#include <optional>
#include <unordered_map>

using OrderList = std::list<Order>;

struct OrderLocation {
    Side side;
    Price price;
    OrderList::iterator iterator;
};
```

Books:

```cpp
std::map<Price, OrderList, std::greater<Price>> bids_;
std::map<Price, OrderList> asks_;
std::unordered_map<OrderId, OrderLocation> order_lookup_;
```

Why:

- `std::map` keeps prices sorted.
- `std::list` preserves FIFO and allows O(1) removal.
- `std::unordered_map` allows fast lookup by order ID.

## Validation Rules

Reject an order if:

- quantity is zero
- price is zero or negative
- order ID already exists

Return `false` for rejected orders.

## Cancel Rules

Canceling an order should:

1. Find it in `order_lookup_`.
2. Remove it from the corresponding price level list.
3. If that price level becomes empty, remove the price level from the book.
4. Remove the ID from `order_lookup_`.
5. Return `true`.

If the ID does not exist, return `false`.

## Example Scenario

Input:

```cpp
book.add_limit_order(1, Side::Sell, 100, 10);
book.add_limit_order(2, Side::Sell, 101, 5);
book.add_limit_order(3, Side::Buy, 100, 7);
```

Expected trade:

```text
TRADE price=100 quantity=7 aggressor_order_id=3 resting_order_id=1
```

Remaining book:

```text
ASK 100 x 3
ASK 101 x 5
```

## Suggested Project Layout

```text
capstone/
  CMakeLists.txt
  include/
    orderbook/
      order_book.hpp
  src/
    order_book.cpp
    main.cpp
  tests/
    order_book_tests.cpp
```

You can copy the simple test harness style from the stage exercises if you want
tests for the capstone.

## Milestone 1: Basic Resting Book

Implement:

- add order without matching
- best bid
- best ask
- quantity at price
- contains order
- print book

At this point, focus on storing orders correctly and preserving FIFO within each
price level.

## Milestone 2: Matching

Implement:

- buy crossing ask
- sell crossing bid
- partial fills
- full fills
- removing empty price levels

Make sure incoming orders match the best available price first and the oldest
order first within that price.

## Milestone 3: Canceling

Implement:

- cancel by order ID
- unknown ID handling
- canceling the last order at a price level

The `order_lookup_` map is what makes canceling direct instead of searching the
whole book.

## Milestone 4: Tests

Write tests for:

- duplicate order ID rejection
- zero quantity rejection
- zero or negative price rejection
- FIFO matching
- partial fill
- full fill
- buy order rests if not fully filled
- sell order rests if not fully filled
- cancel order
- cancel unknown order
- best bid and best ask after trades

## Milestone 5: Extensions

Optional features:

- market orders
- modify order quantity
- modify order price
- trade callback instead of printing
- command-line input
- unit tests with Catch2 or GoogleTest
- benchmark with random orders

A good stretch goal is to make `add_limit_order` return a list of `Trade`
objects instead of printing directly:

```cpp
struct Trade {
    Price price;
    Quantity quantity;
    OrderId aggressor_order_id;
    OrderId resting_order_id;
};
```
