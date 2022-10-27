// Alex Labitigan
// CPSC 120-12
// 2022-10-24
// alexlabitigan@csu.fullerton.edu
// @auhlz
//
// Lab 08-02
// Partners: @Menuk09
//
// Saving message
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void Prompt() {
  std::cout
      << "What's a secret message that you'd like to write into a file?\n";
  std::cout
      << "Type your message out and when you're done press return or enter.\n";
}
int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv, argv + argc};
  if (args.size() < 2) {
    std::cout << "Please provide a path to a file.\n";
    return 1;
  }
  std::string output_file_name{args.at(1)};

  std::ofstream output_file_stream(output_file_name);
  if (!output_file_stream.is_open()) {
    std::cout << "Could not open the file " << output_file_name
              << ". Exiting.\n";
    return 1;
  }
  std::string secret_message;
  Prompt();
  std::getline(std::cin, secret_message, '\n');

  output_file_stream << secret_message << "\n";

  std::cout << "Your secret message was saved into " << output_file_name
            << ".\n";

  output_file_stream.close();

  return 0;
}