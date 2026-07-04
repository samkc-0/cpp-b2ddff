# Stage 01: Core Language

This stage is a practical first pass through the C++ core language. The goal is
not to memorize every feature. The goal is to become comfortable writing small
programs with functions, control flow, references, structs, strings, vectors,
optionals, pairs, headers, and source files.

The exercises live in [src/exercises.cpp](src/exercises.cpp). Public types and
function declarations live in [include/stage01/exercises.hpp](include/stage01/exercises.hpp).
The tests live in [tests/stage01_tests.cpp](tests/stage01_tests.cpp).

## Build

```sh
cmake -S stage-01 -B stage-01/build
cmake --build stage-01/build
```

## Run Tests

Run everything:

```sh
./stage-01/build/stage01_tests
```

Run one exercise:

```sh
./stage-01/build/stage01_tests ex01
./stage-01/build/stage01_tests ex18
```

Run a prefix group:

```sh
./stage-01/build/stage01_tests ex0
```

That runs `ex01` through `ex09`.

## Suggested Workflow

1. Open [src/exercises.cpp](src/exercises.cpp).
2. Start with `ex01`.
3. Run `./stage-01/build/stage01_tests ex01`.
4. Implement only that function.
5. Repeat for the next exercise.

The starter code intentionally compiles, but most tests fail until you implement
the exercises.

## Exercise Map

`ex01`-`ex03`: variables, price arithmetic, return values, sides, and booleans.

`ex04`-`ex08`: order sides, validation rules, `if`, `else`, comparison
operators, and enums.

`ex09`-`ex11`: loops over order vectors and preserving FIFO order.

`ex12`-`ex15`: references, `const`, structs, fills, crossing logic, and price
levels.

`ex16`-`ex21`: `std::optional`, order lookup, cancellation, filtering, and best
bid/best ask.

`ex22`-`ex27`: building price levels, appending orders, removing filled orders,
and matching quantities.

`ex28`-`ex30`: formatting book output, `std::pair`, and final vector filters.

## Capstone

After the exercises pass, build the capstone described in
[capstone/README.md](capstone/README.md). It asks you to write a toy single-
instrument limit order book using the same Stage 1 tools, plus a few standard
library containers introduced by the project brief.
