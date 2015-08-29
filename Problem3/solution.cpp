#include <iostream>
#include <vector>

using namespace std;

// parameters
long N = 600851475143;

bool is_prime(const long &n)
{
   for (long i = 2; i < n; ++i)
   {
      if (n % i == 0)
         return false;
   }

   return true;
}

void get_prime_factors(long n, std::vector<long> &factors)
{
   for (long i = 2; i <= n; ++i)
   {
      if (!(n % i == 0))
         continue;
      if (is_prime(i))
         factors.push_back(i);

         // watch precision here; need to use doubles, not floats
         get_prime_factors(long(double(n)/double(i)), factors);
         return;
   }
}

long get_largest(const std::vector<long> &list)
{
   long largest = 0;
   for (auto &i : list)
   {
      if (i > largest)
         largest = i;
   }

   return largest;
}

int main()
{
   std::vector<long> factors;
   get_prime_factors(N, factors);

   long largest_factor = get_largest(factors);

   cout << "largest prime factor: " << largest_factor << endl;

   return 0;
}
