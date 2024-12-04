#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  fstream file;
  file.open("input.txt");
  vector< string > input;
  string s;
  int count = 0;
  int p2;

  while (getline(file, s)) {
    input.push_back(s);
  }
  // Pretty sure could invoke undefined behavior, but I'm ignoring it
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[i].length(); j++) {
      if (input[i][j] == 'X') {
        // Left and Right
        if (input[i][j + 1] == 'M' && input[i][j + 2] == 'A' &&
            input[i][j + 3] == 'S') {
          count++;
        }
        if (input[i][j - 1] == 'M' && input[i][j - 2] == 'A' &&
            input[i][j - 3] == 'S') {
          count++;
        }

        // Up and Down
        if (input[i + 1][j] == 'M' && input[i + 2][j] == 'A' &&
            input[i + 3][j] == 'S') {
          count++;
        }
        if (input[i - 1][j] == 'M' && input[i - 2][j] == 'A' &&
            input[i - 3][j] == 'S') {
          count++;
        }

        // Diagonals
        if (input[i + 1][j + 1] == 'M' && input[i + 2][j + 2] == 'A' &&
            input[i + 3][j + 3] == 'S') {
          count++;
        }
        if (input[i + 1][j - 1] == 'M' && input[i + 2][j - 2] == 'A' &&
            input[i + 3][j - 3] == 'S') {
          count++;
        }
        if (input[i - 1][j + 1] == 'M' && input[i - 2][j + 2] == 'A' &&
            input[i - 3][j + 3] == 'S') {
          count++;
        }
        if (input[i - 1][j - 1] == 'M' && input[i - 2][j - 2] == 'A' &&
            input[i - 3][j - 3] == 'S') {
          count++;
        }
      }

      if (input[i][j] == 'A') {
        // M S
        //  A
        // M S
        if (input[i - 1][j - 1] == 'M' && input[i - 1][j + 1] == 'S' &&
            input[i + 1][j - 1] == 'M' && input[i + 1][j + 1] == 'S') {
          p2++;
        }

        // M M
        //  A
        // S S
        if (input[i - 1][j - 1] == 'M' && input[i - 1][j + 1] == 'M' &&
            input[i + 1][j - 1] == 'S' && input[i + 1][j + 1] == 'S') {
          p2++;
        }

        // S S
        //  A
        // M M
        if (input[i - 1][j - 1] == 'S' && input[i - 1][j + 1] == 'S' &&
            input[i + 1][j - 1] == 'M' && input[i + 1][j + 1] == 'M') {
          p2++;
        }

        // S M
        //  A
        // S M
        if (input[i - 1][j - 1] == 'S' && input[i - 1][j + 1] == 'M' &&
            input[i + 1][j - 1] == 'S' && input[i + 1][j + 1] == 'M') {
          p2++;
        }
      }
    }
  }
  cout << "Part 1: " << count << endl << "Part 2: " << p2;
}
