#include "exercise.hpp"

#include <stdexcept>
#include <sstream>

namespace stage_01::std_string::reverse_words_exercise {

// Task: Return the words from text in reverse order.
// Collapse repeated whitespace so words are separated by single spaces.
std::string reverse_words(std::string_view text) {
    std::string out;
    std::stringstream ss(std::string{text});
    std::string word;
    std::vector<std::string> words;
    while (ss >> word)
        words.push_back(word);
    for (auto it = words.rbegin(); it != words.rend(); ++it) {
        if (it != words.rbegin())
            out += ' ';
        out += *it;
    }
    return out;
}

}  // namespace stage_01::std_string::reverse_words_exercise
