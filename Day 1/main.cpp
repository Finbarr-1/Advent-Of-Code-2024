#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int p1(vector< int > left, vector< int > right) {
  int output = 0;

  for (int i = 0; i < left.size(); i++) {
    output += abs(left[i] - right[i]);
  }

  return output;
}

int p2(vector< int > left, vector< int > right) {
  int output = 0;

  for (int i = 0; i < left.size(); i++) {
    int n = 0;
    for (int j = 0; j < right.size(); j++) {
      if (left[i] == right[j]) {
        n++;
      }
    }
    output += left[i] * n;
  }

  return output;
}

int main() {
  ifstream file;
  file.open("Input.txt");
  string s;
  vector< int > right;
  vector< int > left;

  // Parsing inputs
  while (getline(file, s)) {
    stringstream line;
    line << s;

    line >> s;
    left.push_back(stoi(s));

    line >> s;
    right.push_back(stoi(s));
  }

  // sorting
  sort(left.begin(), left.end());
  sort(right.begin(), right.end());

  cout << "Part 1: " << p1(left, right) << endl
       << "Part 2: " << p2(left, right) << endl;
}
