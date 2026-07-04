I actually think this works much better if the exercises are small, focused, and cumulative, rather than “build a chess engine.” The goal is to make each exercise teach exactly one new idea. Here’s how I’d structure it.

Modern C++ Curriculum (Specific Exercises)

Stage 1 — Core Language

std::string

* Count vowels
* Count words
* Split a string on spaces
* Join a vector of strings
* Trim whitespace
* Replace all occurrences of a substring
* Check whether a string is a palindrome
* Reverse words in a sentence

std::vector

* Sum elements
* Running totals
* Filter values
* Remove duplicates
* Rotate left/right
* Reverse
* Binary search (manual)
* Merge two sorted vectors
* Sliding window average

std::optional

* Safe divide
* Parse integer
* Find first occurrence
* Find maximum
* Lookup in a map

References & const

* Rewrite APIs to avoid unnecessary copies
* Convert pass-by-value to pass-by-reference
* Add const everywhere appropriate

⸻

Stage 2 — STL Algorithms

Searching

* Rewrite linear search using std::find
* Find first even number
* Find first negative number

Counting

* Count vowels
* Count even numbers
* Count strings longer than N

Transforming

* Square every number
* Convert strings to uppercase
* Extract object names
* Convert Celsius to Fahrenheit

Filtering

* Remove negatives
* Remove duplicates
* Keep only primes
* Keep only long words

Sorting

* Sort integers
* Sort strings
* Sort objects by age
* Sort objects by name
* Stable sort records

Aggregation

* Sum
* Product
* Average
* Dot product
* Histogram

Predicates

* All positive?
* Any duplicates?
* None negative?
* Any empty strings?

⸻

Stage 3 — Classes

Create classes for:

* Fraction
* Complex number
* Date
* Time
* Timer
* Stopwatch
* Bank account
* Wallet
* Student
* Book
* Library
* Rectangle
* Circle
* Matrix
* Chess piece
* Deck of cards

Practice:

* Constructors
* Initialization lists
* Member functions
* Const methods
* Operator overloads (==, <, +, <<)

⸻

Stage 4 — RAII

Write RAII wrappers for:

* File handle
* Timer
* Mutex lock
* Temporary directory
* Logger

Exercises:

* Class that automatically closes a file
* Scoped timer
* Transaction object with rollback
* Temporary configuration override

⸻

Stage 5 — Smart Pointers

Implement:

* Binary tree
* Linked list
* Graph
* Scene graph
* Employee hierarchy

Exercises:

* Convert raw pointers to unique_ptr
* Replace ownership with shared_ptr
* Break cyclic ownership using weak_ptr
* Trace object construction/destruction

⸻

Stage 6 — Templates

Write generic:

* Max function
* Min function
* Swap
* Clamp
* Stack
* Queue
* Ring buffer
* Matrix
* Optional
* Pair

⸻

Stage 7 — Files

Exercises:

* Read entire file
* Count lines
* Count words
* Copy file
* Compare files
* Parse CSV
* Parse INI
* Parse JSON (simple)
* Walk a directory
* Find duplicate files

⸻

Stage 8 — chrono

Exercises:

* Stopwatch
* Countdown timer
* Benchmark sorting algorithms
* Measure function execution
* Timestamp log entries

⸻

Stage 9 — Concurrency

Exercises:

* Spawn one thread
* Join multiple threads
* Parallel sum
* Parallel word count
* Producer-consumer queue
* Thread-safe logger
* Thread pool
* Parallel file search

⸻

Stage 10 — Design

Refactor previous projects to use:

* Composition instead of inheritance
* Interfaces
* Dependency injection
* RAII everywhere
* Value semantics where possible

⸻

Mini Projects (1–2 hours)

* Todo list
* Contact manager
* Calculator
* Markdown parser
* Text statistics
* CSV viewer
* Expense tracker
* Flashcard program
* Address book
* Log analyzer
* Password manager (local)
* Minesweeper logic
* Sudoku solver
* Chess move validator

⸻

Medium Projects (1–2 weeks)

* Chess engine
* HTTP server
* Text editor
* SQLite clone (simplified)
* Git clone (simplified)
* Terminal file manager
* Package manager
* Compiler/interpreter
* 2D game engine
* Chat server
* Build system
* Memory allocator

One thing I’d add is a rule that I’ve found incredibly effective:

Every new stage should begin by refactoring one project from the previous stage.

For example, after learning algorithms, rewrite your vector exercises using std::transform, std::copy_if, and std::accumulate. After learning classes, turn your procedural “contact manager” into a ContactBook class. After learning RAII and smart pointers, revisit a project that manually manages resources. Revisiting familiar code with new tools reinforces why those tools exist far better than starting a brand-new project every time.