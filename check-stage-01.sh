#!/usr/bin/env bash
set -u

verbosity=0

while getopts ":v" option; do
  case "$option" in
    v)
      verbosity=$((verbosity + 1))
      ;;
    *)
      echo "Usage: $0 [-v]" >&2
      exit 2
      ;;
  esac
done

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
build_dir="$repo_root/build"

green_square="🟩"
red_square="🟥"

exercises=(
  "Count vowels|stage_01_std_string_01_count_vowels_tests|stage_01_std_string_01_count_vowels"
  "Count words|stage_01_std_string_02_count_words_tests|stage_01_std_string_02_count_words"
  "Split on spaces|stage_01_std_string_03_split_on_spaces_tests|stage_01_std_string_03_split_on_spaces"
  "Join strings|stage_01_std_string_04_join_strings_tests|stage_01_std_string_04_join_strings"
  "Trim whitespace|stage_01_std_string_05_trim_whitespace_tests|stage_01_std_string_05_trim_whitespace"
  "Replace all|stage_01_std_string_06_replace_all_tests|stage_01_std_string_06_replace_all"
  "Palindrome|stage_01_std_string_07_palindrome_tests|stage_01_std_string_07_palindrome"
  "Reverse words|stage_01_std_string_08_reverse_words_tests|stage_01_std_string_08_reverse_words"
  "Sum elements|stage_01_std_vector_01_sum_elements_tests|stage_01_std_vector_01_sum_elements"
  "Running totals|stage_01_std_vector_02_running_totals_tests|stage_01_std_vector_02_running_totals"
  "Filter values|stage_01_std_vector_03_filter_values_tests|stage_01_std_vector_03_filter_values"
  "Remove duplicates|stage_01_std_vector_04_remove_duplicates_tests|stage_01_std_vector_04_remove_duplicates"
  "Rotate left/right|stage_01_std_vector_05_rotate_left_right_tests|stage_01_std_vector_05_rotate_left_right"
  "Reverse vector|stage_01_std_vector_06_reverse_tests|stage_01_std_vector_06_reverse"
  "Binary search|stage_01_std_vector_07_binary_search_tests|stage_01_std_vector_07_binary_search"
  "Merge sorted vectors|stage_01_std_vector_08_merge_sorted_vectors_tests|stage_01_std_vector_08_merge_sorted_vectors"
  "Sliding window average|stage_01_std_vector_09_sliding_window_average_tests|stage_01_std_vector_09_sliding_window_average"
  "Safe divide|stage_01_std_optional_01_safe_divide_tests|stage_01_std_optional_01_safe_divide"
  "Parse integer|stage_01_std_optional_02_parse_integer_tests|stage_01_std_optional_02_parse_integer"
  "Find first occurrence|stage_01_std_optional_03_find_first_occurrence_tests|stage_01_std_optional_03_find_first_occurrence"
  "Find maximum|stage_01_std_optional_04_find_maximum_tests|stage_01_std_optional_04_find_maximum"
  "Lookup in a map|stage_01_std_optional_05_lookup_in_map_tests|stage_01_std_optional_05_lookup_in_map"
  "Get element|stage_01_std_optional_06_get_element_tests|stage_01_std_optional_06_get_element"
  "Find first even|stage_01_std_optional_07_find_first_even_tests|stage_01_std_optional_07_find_first_even"
  "Parse double|stage_01_std_optional_08_parse_double_tests|stage_01_std_optional_08_parse_double"
  "Average values|stage_01_std_optional_09_average_values_tests|stage_01_std_optional_09_average_values"
  "Find key by value|stage_01_std_optional_10_find_key_by_value_tests|stage_01_std_optional_10_find_key_by_value"
  "Total length|stage_01_references_const_01_total_length_tests|stage_01_references_const_01_total_length"
  "Longest string|stage_01_references_const_02_longest_string_tests|stage_01_references_const_02_longest_string"
  "Append suffix|stage_01_references_const_03_append_suffix_tests|stage_01_references_const_03_append_suffix"
  "Increment all|stage_01_references_const_04_increment_all_tests|stage_01_references_const_04_increment_all"
  "Clamp in place|stage_01_references_const_05_clamp_in_place_tests|stage_01_references_const_05_clamp_in_place"
  "Swap values|stage_01_references_const_06_swap_values_tests|stage_01_references_const_06_swap_values"
  "Copy if greater|stage_01_references_const_07_copy_if_greater_tests|stage_01_references_const_07_copy_if_greater"
  "Scale values|stage_01_references_const_08_scale_values_tests|stage_01_references_const_08_scale_values"
  "Contains word|stage_01_references_const_09_contains_word_tests|stage_01_references_const_09_contains_word"
  "Update if found|stage_01_references_const_10_update_if_found_tests|stage_01_references_const_10_update_if_found"
)

if [[ ! -f "$build_dir/CMakeCache.txt" ]]; then
  if ! cmake -S "$repo_root" -B "$build_dir" >/tmp/check-stage-01-cmake.log 2>&1; then
    echo "$red_square CMake configure"
    exit 1
  fi
fi

failures=0
first_failure_label=""
first_failure_output=""

for exercise in "${exercises[@]}"; do
  IFS="|" read -r label target test_name <<< "$exercise"
  output_file="/tmp/check-stage-01-${test_name}.log"

  if ! cmake --build "$build_dir" --target "$target" >"$output_file" 2>&1; then
    echo "$red_square $label"
    if [[ -z "$first_failure_output" ]]; then
      first_failure_label="$label"
      first_failure_output="$output_file"
    fi
    failures=$((failures + 1))
    continue
  fi

  if ctest --test-dir "$build_dir" -R "^${test_name}$" --output-on-failure >"$output_file" 2>&1; then
    echo "$green_square $label"
  else
    echo "$red_square $label"
    if [[ -z "$first_failure_output" ]]; then
      first_failure_label="$label"
      first_failure_output="$output_file"
    fi
    failures=$((failures + 1))
  fi
done

if [[ "$verbosity" -ge 1 && -n "$first_failure_output" ]]; then
  echo
  echo "First failing exercise: $first_failure_label"
  if [[ "$verbosity" -ge 2 ]]; then
    cat "$first_failure_output"
  else
    sed -n '1,200p' "$first_failure_output"
  fi
fi

if [[ "$failures" -eq 0 ]]; then
  exit 0
fi

exit 1
