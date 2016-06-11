#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef struct square_t {
  unsigned x, y;
  size_t width;
} square_t;

// parameters
unsigned N = 4;

vector<string> split_string(const string &s, const char delimiter)
{
   vector<string> res;

   // ensure the string has atleast one character
   if (s.empty())
      return res;

   size_t pos;
   pos = s.find(delimiter);
   if (pos != string::npos)
   {
      // found it
      res.push_back(s.substr(0, pos));

      vector<string> to_add = split_string(s.substr(pos + 1, s.size()), delimiter);
      res.insert(res.end(), to_add.begin(), to_add.end());
   }
   else
   {
      res.push_back(s);
   }

   return res;
}

int max_adjacent_product(vector< vector<int> > grid, square_t square, unsigned n) {
  int max_product = 0;

  // Compute row products
  for (int i = square.x; i < square.x + square.width; ++i) {
    int row_product = 1;
    for (int j = square.y; j < square.y + square.width; ++j) {
      row_product *= grid[i][j];
    }

    if (row_product > max_product) {
      max_product = row_product;
    }
  }

  // Compute column products
  for (int i = square.x; i < square.x + square.width; ++i) {
    int row_product = 1;
    for (int j = square.y; j < square.y + square.width; ++j) {
      row_product *= grid[j][i];
    }

    if (row_product > max_product) {
      max_product = row_product;
    }
  }

  // Compute diagonal products
  int diagonal_product = 1;
  for (int i = 0; i < square.width; ++i) {
    diagonal_product *= grid[square.x + i][square.y + i];
  }

  if (diagonal_product > max_product) {
    max_product = diagonal_product;
  }

  diagonal_product = 1;
  for (int i = 0; i < square.width; ++i) {
    diagonal_product *= grid[square.x + i][ square.y + (n - 1) - i ];
  }

  if (diagonal_product > max_product) {
    max_product = diagonal_product;
  }

  return max_product;
}

int find_max_adjacent_product(vector< vector<int> > grid, unsigned n) {
  int max_product = 0;

  for (unsigned i = 0; i <= grid.size() - n; ++i) {
    for (unsigned j = 0; j <= grid[i].size() - n; ++j) {
      square_t square;
      square.x = i;
      square.y = j;
      square.width = n;

      int next_max = max_adjacent_product(grid, square, n);
      if (next_max > max_product) {
        max_product = next_max;
      }
    }
  }

  return max_product;
}

// For testing
void print_grid(vector< vector<int> > grid) {
  for (auto next_row : grid) {
    for (auto next_value : next_row) {
      cout << next_value << " ";
    }

    cout << endl;
  }
}

int main()
{
  ifstream in("input.txt");

  if (!in.is_open())
    return -1;

  vector< vector<int> > grid;

  string next_line;
  while (getline(in, next_line))
  {
    stringstream next_line_ss;
    next_line_ss << next_line;
    vector<string> split = split_string(next_line_ss.str(), ' ');

    vector<int> next_row;
    for (auto next : split) {
      next_row.push_back( atoi( next.c_str() ) );
    }

    grid.push_back(next_row);
  }

  int max_product = find_max_adjacent_product(grid, N);

  cout << "Maximum product: " << max_product << endl;

  return 0;
}
