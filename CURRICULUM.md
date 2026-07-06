# Modern C++ Curriculum

I actually think this works much better if the exercises are small, focused, and cumulative, rather than “build a chess engine.” The goal is to make each exercise teach exactly one new idea. Here’s how I’d structure it.

## Stages

* [Stage 1 — Core Language](curriculum/stages/stage-01-core-language.md)
* [Stage 2 — STL Algorithms](curriculum/stages/stage-02-stl-algorithms.md)
* [Stage 3 — Classes](curriculum/stages/stage-03-classes.md)
* [Stage 4 — RAII](curriculum/stages/stage-04-raii.md)
* [Stage 5 — Smart Pointers](curriculum/stages/stage-05-smart-pointers.md)
* [Stage 6 — Templates](curriculum/stages/stage-06-templates.md)
* [Stage 7 — Files](curriculum/stages/stage-07-files.md)
* [Stage 8 — chrono](curriculum/stages/stage-08-chrono.md)
* [Stage 9 — Concurrency](curriculum/stages/stage-09-concurrency.md)
* [Stage 10 — Design](curriculum/stages/stage-10-design.md)

## Projects

* [Mini Projects](curriculum/mini-projects/README.md)
* [Medium Projects](curriculum/medium-projects/README.md)

## Refactoring Rule

One thing I’d add is a rule that I’ve found incredibly effective:

Every new stage should begin by refactoring one project from the previous stage.

For example, after learning algorithms, rewrite your vector exercises using std::transform, std::copy_if, and std::accumulate. After learning classes, turn your procedural “contact manager” into a ContactBook class. After learning RAII and smart pointers, revisit a project that manually manages resources. Revisiting familiar code with new tools reinforces why those tools exist far better than starting a brand-new project every time.

## Exercise Count Rule

Every subsection should include at least 10 focused exercises.
