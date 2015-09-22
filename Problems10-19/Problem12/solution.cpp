/*
   This takes a while to run; the answer for N = 2000000 is: 142913828922
*/

#include <iostream>
#include <vector>

using namespace std;

// parameters
unsigned N = 5;

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
   vector<float> factors;

   float i = 0.0f;
   //for (; factors.size() <= N; ++i)
   while (factors.size() <= N)
   {
      ++i;
      factors = get_factors(float(get_n_triangle(i)));
   }

   // float j = 0.0f;
   // //for (; factors.size() <= N;)
   // while (factors.size() <= N)
   // {
   //    j = j + (j + 1);
   //
   //    factors = get_factors(float(j));
   // }

   cout << "number with over " << N << " factors is: " << get_n_triangle(i) << endl;

   return 0;
}
