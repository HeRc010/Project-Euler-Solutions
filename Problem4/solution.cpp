#include <iostream>
#include <string>
#include <sstream>

// for reversing string
#include <algorithm>

using namespace std;

// parameters
const unsigned digit_count = 3;

bool is_palindrome(const unsigned n)
{
   stringstream ss;
   ss << n;

   // ensure the number of digits is even
   if (ss.str().size() % 2 != 0)
      return false;

   unsigned mid_point = unsigned(ss.str().size()/2.0f);
   string upper_half = ss.str().substr(0, mid_point);
   string lower_half = ss.str().substr(mid_point, ss.str().size());
   reverse(lower_half.begin(), lower_half.end());

   if (upper_half == lower_half)
      return true;

   return false;
}

// slow but works
unsigned power(unsigned base, unsigned exponent)
{
   unsigned result = 1;
   for(unsigned i = 0; i < exponent; ++i)
   {
      result *= base;
   }

   return result;
}

unsigned pair_product(const pair<unsigned, unsigned> &p)
{
   return p.first * p.second;
}

int main()
{
   std::pair<unsigned, unsigned> largest_palindrome_pair(0, 0);
   const unsigned upper_bound = power(10, digit_count);

   for (unsigned i = 0; i < upper_bound; ++i)
   {
      for (unsigned j = 0; j < upper_bound; ++j)
      {
         pair<unsigned, unsigned> p(i, j);
         if (!is_palindrome(pair_product(p)))
            continue;

         if (pair_product(p) > pair_product(largest_palindrome_pair))
         {
            largest_palindrome_pair = p;
         }
      }
   }

   cout << "largest palindrome is: " << largest_palindrome_pair.first * largest_palindrome_pair.second << " using the numbers: " << largest_palindrome_pair.first << ", " << largest_palindrome_pair.second << endl;

   return 0;
}
