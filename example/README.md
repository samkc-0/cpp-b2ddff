# C++ Iterable Exercises

This repo contains 30 small exercises for practicing C++ iterables, especially
`std::vector`, strings, iterator pairs, maps, sets, algorithms, and range-style
loops.

The exercises live in [include/iterables/exercises.hpp](include/iterables/exercises.hpp).
Each function has a short prompt and a `TODO` implementation. The tests live in
[tests/iterables_tests.cpp](tests/iterables_tests.cpp).

## Build

```sh
cmake -S . -B build
cmake --build build
```

## Run tests

Run everything:

```sh
./build/iterables_tests
```

Run one exercise:

```sh
./build/iterables_tests ex01
./build/iterables_tests ex14
```

Run a prefix group:

```sh
./build/iterables_tests ex0
```

That runs `ex01` through `ex09`.

## Suggested workflow

1. Open `include/iterables/exercises.hpp`.
2. Start with `ex01`.
3. Run `./build/iterables_tests ex01`.
4. Implement only that function.
5. Repeat for `ex02`, `ex03`, and so on.

The starter code intentionally compiles but most tests fail until you implement
the exercises.
