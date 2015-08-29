#include <iostream>
#include <vector>

using namespace std;

// parameters
long N = 10001;

bool is_prime(long n)
{
   for (long i = 2; i < n; ++i)
   {
      if (n % i == 0)
         return false;
   }

   return true;
}

std::vector<long> get_first_n_primes(long n)
{
   std::vector<long> res;
   long next_value = 2;
   while (res.size() != n)
   {
      if (is_prime(next_value))
         res.push_back(next_value);
      ++next_value;
   }

   return res;
}

int main()
{
   std::vector<long> primes = get_first_n_primes(N);

   cout << "the " <<  N << "th prime is: " << primes.back() << endl;

   return 0;
}
