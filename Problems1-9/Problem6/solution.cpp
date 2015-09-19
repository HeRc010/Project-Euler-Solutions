#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// for reversing string
#include <algorithm>

using namespace std;

// parameters
unsigned first_n = 100;

long square(long n)
{
   return n * n;
}

long sum(unsigned n)
{
   long res = 0;
   for (unsigned i = 0; i <= n; ++i)
   {
      res += i;
   }

   return res;
}

long sum_of_squares(unsigned n)
{
   long res = 0;
   for (unsigned i = 1; i <= n; ++i)
   {
      res += square(i);
   }

   return res;
}

int main()
{
   long value = square(sum(first_n)) - sum_of_squares(first_n);

   cout << "Result is: " << value << endl;

   return 0;
}
