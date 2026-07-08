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
  "Fraction|stage_03_classes_01_fraction_tests|stage_03_classes_01_fraction"
  "Complex number|stage_03_classes_02_complex_number_tests|stage_03_classes_02_complex_number"
  "Date|stage_03_classes_03_date_tests|stage_03_classes_03_date"
  "Time|stage_03_classes_04_time_tests|stage_03_classes_04_time"
  "Timer|stage_03_classes_05_timer_tests|stage_03_classes_05_timer"
  "Stopwatch|stage_03_classes_06_stopwatch_tests|stage_03_classes_06_stopwatch"
  "Bank account|stage_03_classes_07_bank_account_tests|stage_03_classes_07_bank_account"
  "Wallet|stage_03_classes_08_wallet_tests|stage_03_classes_08_wallet"
  "Student|stage_03_classes_09_student_tests|stage_03_classes_09_student"
  "Book|stage_03_classes_10_book_tests|stage_03_classes_10_book"
  "Library|stage_03_classes_11_library_tests|stage_03_classes_11_library"
  "Rectangle|stage_03_classes_12_rectangle_tests|stage_03_classes_12_rectangle"
  "Circle|stage_03_classes_13_circle_tests|stage_03_classes_13_circle"
  "Matrix|stage_03_classes_14_matrix_tests|stage_03_classes_14_matrix"
  "Chess piece|stage_03_classes_15_chess_piece_tests|stage_03_classes_15_chess_piece"
  "Deck of cards|stage_03_classes_16_deck_of_cards_tests|stage_03_classes_16_deck_of_cards"
  "Default constructor|stage_03_practice_01_default_constructor_tests|stage_03_practice_01_default_constructor"
  "Initialization list|stage_03_practice_02_initialization_list_tests|stage_03_practice_02_initialization_list"
  "Member functions|stage_03_practice_03_member_functions_tests|stage_03_practice_03_member_functions"
  "Const methods|stage_03_practice_04_const_methods_tests|stage_03_practice_04_const_methods"
  "Equality operator|stage_03_practice_05_equality_operator_tests|stage_03_practice_05_equality_operator"
  "Less-than operator|stage_03_practice_06_less_than_operator_tests|stage_03_practice_06_less_than_operator"
  "Addition operator|stage_03_practice_07_addition_operator_tests|stage_03_practice_07_addition_operator"
  "Stream output operator|stage_03_practice_08_stream_output_operator_tests|stage_03_practice_08_stream_output_operator"
  "Compound assignment|stage_03_practice_09_compound_assignment_tests|stage_03_practice_09_compound_assignment"
  "Const-correct API|stage_03_practice_10_const_correct_api_tests|stage_03_practice_10_const_correct_api"
)

if [[ ! -f "$build_dir/CMakeCache.txt" ]]; then
  if ! cmake -S "$repo_root" -B "$build_dir" >/tmp/check-stage-03-cmake.log 2>&1; then
    echo "$red_square CMake configure"
    exit 1
  fi
fi

failures=0
first_failure_label=""
first_failure_output=""

for exercise in "${exercises[@]}"; do
  IFS="|" read -r label target test_name <<< "$exercise"
  output_file="/tmp/check-stage-03-${test_name}.log"

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
