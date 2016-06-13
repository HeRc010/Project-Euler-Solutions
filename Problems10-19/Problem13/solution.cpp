#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <cassert>
#include <algorithm>

using namespace std;

// parameters
const unsigned N = 4;

void print_digits(const list<unsigned> &digits) {
  for (auto next_digit : digits) {
    cout << next_digit;
  }

  cout << endl;
}

list<unsigned> get_digits(const string &value) {
  list<unsigned> digits;

  char next_digit[1];
  for (size_t i = 0; i < value.size(); ++i) {
    next_digit[0] = value[i];

    digits.push_back(atoi(next_digit));
  }

  return digits;
}

list<unsigned> zeros() {
  list<unsigned> digits;
  for (size_t i = 0; i < N; ++i) {
    digits.push_back(0);
  }

  return digits;
}

list<unsigned> add(const list<unsigned> &value1, const list<unsigned> &value2) {
  list<unsigned> a, b;
  if (value1.size() < value2.size()) {
    a = value1;
    b = value2;
  } else {
    a = value2;
    b = value1;
  }

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  for (size_t i = a.size(); i < b.size(); ++i) {
    a.push_back(0);
  }

  assert(a.size() == b.size());

  list<unsigned> result;

  unsigned carry = 0;
  for (auto a_it = a.begin(), b_it = b.begin(); a_it != a.end(); ++a_it, ++b_it) {
    unsigned digit_sum = *a_it + *b_it + carry;
    if (digit_sum > 9) {
      result.push_back(digit_sum % 10);
      carry = 1;
    } else {
      result.push_back(digit_sum);
      carry = 0;
    }
  }

  if (carry) result.push_back(carry);

  reverse(result.begin(), result.end());

  return result;
}

int main() {
  ifstream in("input.txt");

  if (!in.is_open())
    return -1;

  list<unsigned> sum = zeros();
  string next_line;
  while (getline(in, next_line)) {
    list<unsigned> next_digits = get_digits(next_line);
    sum = add(sum, next_digits);
  }

  cout << "The sum is: ";
  print_digits(sum);

  return 0;
}
