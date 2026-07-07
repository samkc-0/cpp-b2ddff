# Stage 1 std::optional Feedback

All `03-std-optional` exercises are passing in `./check-stage-01.sh`. Overall: good work. The implementations are mostly simple and correct for the provided tests.

## Notes

1. `parse_integer`

   This works for the current tests, but `"-"` will pass the character checks and then `std::stoi` will throw. Since the exercise returns `std::optional`, it should probably catch parse failures and return `std::nullopt` instead of letting exceptions escape. Same for out-of-range numbers.

2. `find_first_occurrence`

   Correct, but it uses `std::find` without including `<algorithm>`. It may compile due to indirect includes, but the file should include what it uses.

3. `get_element`

   `index < 0` is unnecessary because `std::size_t` is unsigned. This condition is always false:

   ```cpp
   if (index < 0 || index >= values.size())
   ```

   Prefer:

   ```cpp
   if (index >= values.size())
   ```

4. `find_first_even`

   Correct, but this extra reference does not add anything:

   ```cpp
   const std::vector<int>& v = values;
   ```

   Use `values.begin()` and `values.end()` directly. Also include `<algorithm>` for `std::find_if`.

5. `parse_double`

   Solid approach: checking `pos != text.size()` after `std::stod` is the right idea. Add `<algorithm>` for `std::any_of` and `<cctype>` for `std::isspace`.

6. `lookup_in_map`

   Correct. The `std::string(key)` conversion is acceptable here. Later, transparent comparators can avoid that allocation, but it is not important at this stage.

## Suggested Cleanup

Add missing standard headers and make `parse_integer` exception-safe.
