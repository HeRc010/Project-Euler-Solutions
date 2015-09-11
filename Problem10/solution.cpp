/*
   This takes a while to run; the answer for N = 2000000 is: 142913828922
*/

#include <iostream>

using namespace std;

// parameters
long N = 2000000;

bool is_prime(const long n)
{
   for (long i = 2; i < n; ++i)
   {
      if (n % i == 0)
         return false;
   }

   return true;
}

int main()
{
   long sum = 0;
   for (long i = 2; i < N; ++i)
   {
      if (is_prime(i))
         sum += i;
   }

   cout << "sum is: " << sum << endl;

   return 0;
}
