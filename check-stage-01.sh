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
