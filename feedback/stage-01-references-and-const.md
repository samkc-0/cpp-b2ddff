# Stage 1 References & const Feedback

All `04-references-and-const` exercises are passing in `./check-stage-01.sh`. Overall: these are correct and show the main idea of the section: use `const&` for read-only data and non-const `&` when the function intentionally mutates caller-owned state.

## Notes

1. `total_length`

   Good use of `const std::string&` in the loop. Small style point: use `std::size_t` instead of `size_t` to match the function return type and avoid relying on global namespace aliases.

2. `longest_string`

   Correct and avoids returning a dangling view. The returned `std::string_view` refers to a string inside the caller-owned vector, which is exactly the concept here.

   One subtle point: if the caller later mutates or destroys the vector, the returned view becomes invalid. That is acceptable for this exercise, but it is the main lifetime rule to remember with `std::string_view`.

3. `append_suffix`

   Correct. Nice use of `auto&` because the loop is mutating each string. This clearly practices non-const references.

4. `increment_all`

   Correct. `++x` is slightly more idiomatic than `x++` when the old value is not needed, though for `int` there is no practical difference.

5. `clamp_in_place`

   Correct for the tests. The two independent `if` statements are fine when `minimum <= maximum`. If you later wanted to harden this API, you would decide what should happen when `minimum > maximum`.

6. `swap_values`

   Correct. This is a good minimal demonstration of reference parameters. Later, prefer `std::swap(left, right)` for real code.

7. `copy_if_greater`

   Correct behavior. Since `source` is const, the loop variable should also be const:

   ```cpp
   for (const auto& x : source)
   ```

   Or, because `int` is cheap to copy:

   ```cpp
   for (int x : source)
   ```

8. `scale_values`

   Correct. Copying the input into `out` and then mutating `out` is a clean way to preserve the original vector.

9. `contains_word`

   Correct behavior. Same const-loop note as above:

   ```cpp
   for (const auto& w : words)
   ```

   That communicates that the loop does not mutate the strings.

10. `update_if_found`

   Correct and importantly does not insert missing keys. The `std::string` conversion is reasonable because the map uses `std::string` keys. Later, transparent lookup can avoid that allocation, but it is not needed here.

## Suggested Cleanup

Use `const auto&` in read-only loops, use `std::size_t` consistently, and consider `std::swap` in `swap_values`.
