/*
   This takes a while to run; the answer for N = 2000000 is: 142913828922
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// parameters
unsigned N = 500;
map<float, vector<float>> cache;

bool contains(const vector<float> &vec, float val)
{
   for (unsigned i = 0; i < vec.size(); ++i)
   if (vec[i] == val)
   {
      return true;
   }

   return false;
}

vector<float> get_factors(float number)
{
   vector<float> factors;
   factors.push_back(number);

   if (number == 1.0f)
      return factors;

   factors.push_back(1.0f);

   for (float i = 2.0f; i < number; ++i)
   {
      if ((unsigned(number) % unsigned(i)) == 0)
         factors.push_back(i);
   }

   return factors;
}

vector<float> get_factors_other(float number)
{
   vector<float> factors;
   // factors.push_back(number);
   //
   // if (number == 1.0f)
   //    return factors;
   //
   // factors.push_back(1.0f);

   auto entry = cache.find(number);
   if (entry != cache.end())
   {
      return entry->second;
   }

   for (float i = 2.0f; i < number; ++i)
   {
      if ((unsigned(number) % unsigned(i)) == 0)
      {
         factors.push_back(i);
         vector<float> nested_factors = get_factors_other(number/i);
      }
   }

   // add factors to cache
   cache[number] = factors;

   return factors;
}

unsigned get_n_triangle(unsigned n)
{
   unsigned val = 0;
   for (unsigned i = 1; i <= n; ++i)
   {
      val += i;
   }

   return val;
}

int main()
{
   vector<float> factors; // = get_factors_other(28.0f); // test

   // for (unsigned i = 0; i < factors.size(); ++i)
   // {
   //    cout << factors[i] << endl;
   // }
   //
   // return 0;

   // float i = 0.0f;
   // //for (; factors.size() <= N; ++i)
   // while (factors.size() <= N)
   // {
   //    ++i;
   //    factors = get_factors(float(get_n_triangle(i)));
   // }

   // float j = 0.0f;
   // //for (; factors.size() <= N;)
   // while (factors.size() <= N)
   // {
   //    j = j + (j + 1);
   //
   //    factors = get_factors(float(j));
   // }

   float next_triangle = 0.0f;
   for (unsigned k = 1; (factors.size() + 2) <= N; ++k)
   {
      next_triangle += k;

      factors = get_factors_other(float(next_triangle));
   }

   cout << "number with over " << N << " factors is: " << next_triangle << endl;

   // for (auto &p : cache)
   // {
   //    cout << p.first << " :" << endl;
   //    for (auto &item : p.second)
   //    {
   //       cout << item << endl;
   //    }
   // }

   return 0;
}
