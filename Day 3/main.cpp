#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int p1() {
  ifstream file;
  file.open("test.txt");
  string s;
  vector< pair< int, int > > results;
  int output = 0;

  while (getline(file, s)) {
    regex pattern("mul\\((\\d+),(\\d+)\\)");
    sregex_iterator begin(s.begin(), s.end(), pattern);
    sregex_iterator end;

    for (auto it = begin; it != end; ++it) {
      int x = stoi((*it)[1].str());
      int y = stoi((*it)[2].str());
      results.emplace_back(x, y);
    }
  }

  for (auto &pair : results) {
    output += pair.first * pair.second;
  }
  return output;
}

int p2() {
  ifstream file;
  file.open("test.txt");
  string s;
  vector< pair< int, int > > results;
  int output = 0;
  bool is_do = false;

  while (getline(file, s)) {
    regex pattern("(do\\(\\)|don't\\(\\))|mul\\((\\d+),(\\d+)\\)");
    sregex_iterator begin(s.begin(), s.end(), pattern);
    sregex_iterator end;

    for (auto it = begin; it != end; ++it) {
      std::smatch match = *it;
      if (match.str() == "do()") {
        is_do = true;
      } else if (match.str() == "don't()") {
        is_do = false;
      } else if (match[1].matched && match[2].matched) { // Matched `mul(x,y)`
        if (is_do) {

          int x = std::stoi(match[1].str());
          int y = std::stoi(match[2].str());
          results.emplace_back(x, y);
        }
      }
    }
    for (auto &pair : results) {
      output += pair.first * pair.second;
    }
    return output;
  }

  for (auto &pair : results) {
    cout << "x: " << pair.first << ", y: " << pair.second << endl;
    output += pair.first * pair.second;
  }
}

int main() { cout << "Part 1: " << p1() << endl << "Part 2: " << p2() << endl; }
