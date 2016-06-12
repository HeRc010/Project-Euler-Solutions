/*
   This takes a while to run; the answer for N = 500 is: 76576500, with 576 divisors
*/

#include <iostream>
#include <vector>

using namespace std;

// parameters
const unsigned N = 500;

vector<unsigned> get_divisors(unsigned value) {
  vector<unsigned> factors;
  for (unsigned i = 1; i <= value; ++i) {
    if ( (value % i) == 0 ) {
      factors.push_back(i);
    }
  }

  return factors;
}

int main() {
  unsigned i = 1, next_value = 1;
  while (true) {
    vector<unsigned> divisors = get_divisors(next_value);

    cout << "Next number: " << next_value << ", factor count: " << divisors.size() << endl;

    if (divisors.size() > N) break;

    i += 1;
    next_value += i;
  }

  cout << "First triangular number with more than " << N << " divisors is: " << next_value << endl;

  return 0;
}
