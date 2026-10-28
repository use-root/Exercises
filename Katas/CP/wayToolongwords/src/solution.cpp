#include <iostream>
#include <string>
#include <vector>

std::string abbreviation(std::string word) {
  if (word.size() <= 10)
    return word;
  std::string abbr;
  abbr += word[0];
  abbr += std::to_string(word.size() - 2);
  abbr += word.back();
  return abbr;
}

std::vector<std::string> process(std::vector<std::string> &words) {
  std::vector<std::string> result;
  for (const auto &word : words) {
    result.push_back(abbreviation(word));
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::string> words(n);

  for (int i = 0; i < n; i++)
    std::cin >> words[i];

  std::vector<std::string> abbr_words = process(words);
  for (const auto &word : abbr_words)
    std::cout << word << "\n";
}
