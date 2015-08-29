#include <iostream>

using namespace std;

// parameters
unsigned value_0 = 1;
unsigned value_1 = 2;

// gives the n-th fibonacci number
unsigned fib(unsigned index)
{
  if (index == 0)
    return value_0;
  if (index == 1)
    return value_1;

  return fib(index - 1) + fib(index - 2);
}

int main()
{
  unsigned sum = 0, next_fib = 0;
  for (unsigned i = 0; next_fib < 4000000; ++i)
  {
    next_fib = fib(i);
    
    if (next_fib % 2 == 0)
    {
      sum += next_fib;
    }
  }

  cout << "sum: " << sum << endl;
  
  return 0;
}
