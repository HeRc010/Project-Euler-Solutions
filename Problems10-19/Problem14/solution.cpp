#include <iostream>

using namespace std;

// parameters
const unsigned N = 1000000;

unsigned get_chain_length(unsigned n) {
  if (n == 1) return 1;

  if ( (n % 2) == 0 ) {
    n = n / 2;
  } else {
    n = 3 * n + 1;
  }

  return 1 + get_chain_length(n);
}

unsigned get_max_length(unsigned n) {
  unsigned max = 0;
  for (unsigned i = 1; i < n; ++i) {
    unsigned next_length = get_chain_length(i);
    if (next_length > max) {
      max = next_length;
    }
  }

  return max;
}

int main() {
  cout << "N = 13 chain length: " << get_chain_length(13) << endl;

  cout << "Maximum length is: " << get_max_length(N) << endl;

  return 0;
}
