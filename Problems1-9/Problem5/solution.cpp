#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// for reversing string
#include <algorithm>

using namespace std;

// parameters
unsigned N = 20;

long factorial(unsigned n)
{
   long res = 1;
   for (unsigned i = 1; i < N; ++i)
   {
      res *= i;
   }

   return res;
}

bool divides_evenly(long val, unsigned n)
{
   for (unsigned i = 1; i < n; ++i )
   {
      if (val % i != 0)
         return false;
   }

   return true;
}

int main()
{
   long min = factorial(N);
   for (long i = 1; i < min; ++i)
   {
      if (divides_evenly(i, N))
      {
         min = i;
         break;
      }
   }

   cout << "The minimum value is: " << min << endl;

   return 0;
}
