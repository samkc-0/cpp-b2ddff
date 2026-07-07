#!/usr/bin/env bash
set -u

verbosity=0

usage() {
  cat >&2 <<EOF
Usage: $0 [-v] [subsection ...]

Subsections:
  all
  std-string | std::string | string | strings
  std-vector | std::vector | vector | vectors
  std-optional | std::optional | optional | option
  references-and-const | references | const
EOF
}

while getopts ":vh" option; do
  case "$option" in
    v)
      verbosity=$((verbosity + 1))
      ;;
    h)
      usage
      exit 0
      ;;
    *)
      usage
      exit 2
      ;;
  esac
done
shift $((OPTIND - 1))

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
build_dir="$repo_root/build"

green_square="🟩"
red_square="🟥"

exercises=(
  "std-string|Count vowels|stage_01_std_string_01_count_vowels_tests|stage_01_std_string_01_count_vowels"
  "std-string|Count words|stage_01_std_string_02_count_words_tests|stage_01_std_string_02_count_words"
  "std-string|Split on spaces|stage_01_std_string_03_split_on_spaces_tests|stage_01_std_string_03_split_on_spaces"
  "std-string|Join strings|stage_01_std_string_04_join_strings_tests|stage_01_std_string_04_join_strings"
  "std-string|Trim whitespace|stage_01_std_string_05_trim_whitespace_tests|stage_01_std_string_05_trim_whitespace"
  "std-string|Replace all|stage_01_std_string_06_replace_all_tests|stage_01_std_string_06_replace_all"
  "std-string|Palindrome|stage_01_std_string_07_palindrome_tests|stage_01_std_string_07_palindrome"
  "std-string|Reverse words|stage_01_std_string_08_reverse_words_tests|stage_01_std_string_08_reverse_words"
  "std-vector|Sum elements|stage_01_std_vector_01_sum_elements_tests|stage_01_std_vector_01_sum_elements"
  "std-vector|Running totals|stage_01_std_vector_02_running_totals_tests|stage_01_std_vector_02_running_totals"
  "std-vector|Filter values|stage_01_std_vector_03_filter_values_tests|stage_01_std_vector_03_filter_values"
  "std-vector|Remove duplicates|stage_01_std_vector_04_remove_duplicates_tests|stage_01_std_vector_04_remove_duplicates"
  "std-vector|Rotate left/right|stage_01_std_vector_05_rotate_left_right_tests|stage_01_std_vector_05_rotate_left_right"
  "std-vector|Reverse vector|stage_01_std_vector_06_reverse_tests|stage_01_std_vector_06_reverse"
  "std-vector|Binary search|stage_01_std_vector_07_binary_search_tests|stage_01_std_vector_07_binary_search"
  "std-vector|Merge sorted vectors|stage_01_std_vector_08_merge_sorted_vectors_tests|stage_01_std_vector_08_merge_sorted_vectors"
  "std-vector|Sliding window average|stage_01_std_vector_09_sliding_window_average_tests|stage_01_std_vector_09_sliding_window_average"
  "std-optional|Safe divide|stage_01_std_optional_01_safe_divide_tests|stage_01_std_optional_01_safe_divide"
  "std-optional|Parse integer|stage_01_std_optional_02_parse_integer_tests|stage_01_std_optional_02_parse_integer"
  "std-optional|Find first occurrence|stage_01_std_optional_03_find_first_occurrence_tests|stage_01_std_optional_03_find_first_occurrence"
  "std-optional|Find maximum|stage_01_std_optional_04_find_maximum_tests|stage_01_std_optional_04_find_maximum"
  "std-optional|Lookup in a map|stage_01_std_optional_05_lookup_in_map_tests|stage_01_std_optional_05_lookup_in_map"
  "std-optional|Get element|stage_01_std_optional_06_get_element_tests|stage_01_std_optional_06_get_element"
  "std-optional|Find first even|stage_01_std_optional_07_find_first_even_tests|stage_01_std_optional_07_find_first_even"
  "std-optional|Parse double|stage_01_std_optional_08_parse_double_tests|stage_01_std_optional_08_parse_double"
  "std-optional|Average values|stage_01_std_optional_09_average_values_tests|stage_01_std_optional_09_average_values"
  "std-optional|Find key by value|stage_01_std_optional_10_find_key_by_value_tests|stage_01_std_optional_10_find_key_by_value"
  "references-and-const|Total length|stage_01_references_const_01_total_length_tests|stage_01_references_const_01_total_length"
  "references-and-const|Longest string|stage_01_references_const_02_longest_string_tests|stage_01_references_const_02_longest_string"
  "references-and-const|Append suffix|stage_01_references_const_03_append_suffix_tests|stage_01_references_const_03_append_suffix"
  "references-and-const|Increment all|stage_01_references_const_04_increment_all_tests|stage_01_references_const_04_increment_all"
  "references-and-const|Clamp in place|stage_01_references_const_05_clamp_in_place_tests|stage_01_references_const_05_clamp_in_place"
  "references-and-const|Swap values|stage_01_references_const_06_swap_values_tests|stage_01_references_const_06_swap_values"
  "references-and-const|Copy if greater|stage_01_references_const_07_copy_if_greater_tests|stage_01_references_const_07_copy_if_greater"
  "references-and-const|Scale values|stage_01_references_const_08_scale_values_tests|stage_01_references_const_08_scale_values"
  "references-and-const|Contains word|stage_01_references_const_09_contains_word_tests|stage_01_references_const_09_contains_word"
  "references-and-const|Update if found|stage_01_references_const_10_update_if_found_tests|stage_01_references_const_10_update_if_found"
)

normalize_subsection() {
  case "$1" in
    all)
      echo "all"
      ;;
    01-std-string | std-string | std::string | string | strings)
      echo "std-string"
      ;;
    02-std-vector | std-vector | std::vector | std::vectors | vector | vectors)
      echo "std-vector"
      ;;
    03-std-optional | std-optional | std::optional | std::option | optional | option)
      echo "std-optional"
      ;;
    04-references-and-const | references-and-const | references | reference | refs | const)
      echo "references-and-const"
      ;;
    *)
      return 1
      ;;
  esac
}

selected_subsections=()
if [[ "$#" -eq 0 ]]; then
  selected_subsections=("all")
else
  for requested_subsection in "$@"; do
    if ! normalized_subsection="$(normalize_subsection "$requested_subsection")"; then
      echo "Unknown subsection: $requested_subsection" >&2
      usage
      exit 2
    fi
    selected_subsections+=("$normalized_subsection")
  done
fi

subsection_selected() {
  local subsection="$1"

  for selected_subsection in "${selected_subsections[@]}"; do
    if [[ "$selected_subsection" == "all" || "$selected_subsection" == "$subsection" ]]; then
      return 0
    fi
  done

  return 1
}

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
  IFS="|" read -r subsection label target test_name <<< "$exercise"
  if ! subsection_selected "$subsection"; then
    continue
  fi

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
