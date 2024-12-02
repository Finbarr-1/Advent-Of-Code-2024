#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct report {
  vector< int > levels;

  bool safe1() {
    // Checking if the levels are sorted in either ascending or descenging order
    if (is_sorted(levels.begin(), levels.end()) ||
        is_sorted(levels.rbegin(), levels.rend())) {
      for (int i = 0; i < levels.size() - 1; i++) {
        // Checking if there is a greater than 3 jump in levels or if there is
        // no change between two levels
        if (abs(levels[i] - levels[i + 1]) > 3 ||
            abs(levels[i] - levels[i + 1]) == 0) {
          return false;
        }
      }
      return true;
    }
    return false;
  }

  bool safe2() {
    for (int i = 0; i < levels.size(); i++) {
      report temp;
      // Removing one level from the list at a time and checking if it is safe
      // after
      copy(levels.begin(), levels.begin() + i, back_inserter(temp.levels));
      copy(levels.begin() + i + 1, levels.end(), back_inserter(temp.levels));
      if (temp.safe1()) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  ifstream file;
  file.open("Input.txt");
  string s;
  int output1 = 0;
  int output2 = 0;

  // Parsing inputs
  while (getline(file, s)) {
    report line;
    stringstream ss;

    ss << s;

    while (ss >> s) {
      line.levels.push_back(stoi(s));
    }
    if (line.safe1()) {
      output1++;
    }
    if (line.safe2()) {
      output2++;
    }
  }
  cout << "Part 1:" << output1 << endl << "Part 2:" << output2 << endl;
}
