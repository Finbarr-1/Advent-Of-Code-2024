#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main() {
  std::string input =
      "do()mul(2,4)%&don't()mul[3,7]!@^mul(5,5)+do()mul(8,5)then(mul(11,8))";

  // Regex to match `do()`, `don't()`, and `mul(x, y)`
  std::regex regex_pattern("do\\(\\)|don't\\(\\)|mul\\((\\d+),(\\d+)\\)");
  std::sregex_iterator begin(input.begin(), input.end(), regex_pattern);
  std::sregex_iterator end;

  std::vector< std::pair< int, int > > results;
  bool is_do_active = false; // Track if `do()` is active

  for (auto it = begin; it != end; ++it) {
    std::smatch match = *it;

    if (match.str() == "do()") {
      is_do_active = true;
    } else if (match.str() == "don't()") {
      is_do_active = false;
    } else if (match[1].matched && match[2].matched) { // Matched mul(x,y)
      if (is_do_active) {
        int x = std::stoi(match[1].str());
        int y = std::stoi(match[2].str());
        results.emplace_back(x, y);
      }
    }
  }

  // Print the results
  for (const auto &pair : results) {
    std::cout << "x: " << pair.first << ", y: " << pair.second << std::endl;
  }

  return 0;
}
// int p1() {
//   ifstream file;
//   file.open("test.txt");
//   string s;
//   vector< pair< int, int > > results;
//   int output = 0;

//   while (getline(file, s)) {
//     regex pattern("mul\\((\\d+),(\\d+)\\)");
//     sregex_iterator begin(s.begin(), s.end(), pattern);
//     sregex_iterator end;

//     for (auto it = begin; it != end; ++it) {
//       int x = stoi((*it)[1].str());
//       int y = stoi((*it)[2].str());
//       results.emplace_back(x, y);
//     }
//   }

//   for (auto &pair : results) {
//     output += pair.first * pair.second;
//   }
//   return output;
// }

// int p2() {
//   ifstream file;
//   file.open("test.txt");
//   string s;
//   vector< pair< int, int > > results;
//   int output = 0;
//   bool is_do = false;

//   while (getline(file, s)) {
//     regex pattern("(do\\(\\)|don't\\(\\))|mul\\((\\d+),(\\d+)\\)");
//     sregex_iterator begin(s.begin(), s.end(), pattern);
//     sregex_iterator end;

//     for (auto it = begin; it != end; ++it) {
//       std::smatch match = *it;
//       if (match.str() == "do()") {
//         is_do = true;
//       } else if (match.str() == "don't()") {
//         is_do = false;
//       } else if (match[1].matched && match[2].matched) { // Matched `mul(x,
//       y)`
//         if (is_do) {

//           int x = std::stoi(match[1].str());
//           int y = std::stoi(match[2].str());
//           results.emplace_back(x, y);
//         }
//       }
//     }
//     for (auto &pair : results) {
//       output += pair.first * pair.second;
//     }
//     return output;
//   }

//   for (auto &pair : results) {
//     cout << "x: " << pair.first << ", y: " << pair.second << endl;
//     output += pair.first * pair.second;
//   }
// }

// int main() { cout << "Part 1: " << p1() << endl << "Part 2: " << p2() <<
// endl; }
