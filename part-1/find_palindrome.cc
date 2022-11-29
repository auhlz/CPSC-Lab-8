// Alex Labitigan
// CPSC 120-12
// 2022-10-24
// alexlabitigan@csu.fullerton.edu
// @auhlz
//
// Lab 08-01
// Partners: @Menulk09
//
// Fidning Palindrome
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool IsPalindrome(const std::string& word) {
  bool same_word = false;
  std::string reverse_word{word.rbegin(), word.rend()};
  if (word == reverse_word) {
    same_word = true;
  }
  return same_word;
}
int main(int argc, char const* argv[]) {
  std::vector<std::string> args{argv, argv + argc};
  if (args.size() < 2) {
    std::cout << "Please provide a path to a file. Exiting.\n";
    return 1;
  }
  std::string input_file_name{args.at(1)};
  std::ifstream input_file_stream{input_file_name};

  if (!input_file_stream.is_open()) {
    std::cout << "Could not open the file " << input_file_name
              << ". Exiting.\n";
    return 1;
  }

  while (input_file_stream.good()) {
    std::string line_buffer;
    std::getline(input_file_stream, line_buffer);
    if (line_buffer.size() > 3 && IsPalindrome(line_buffer)) {
      std::cout << line_buffer << "\n";
    }
  }
  input_file_stream.close();

  return 0;
}