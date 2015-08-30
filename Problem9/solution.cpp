#include <iostream>
#include <cmath>

using namespace std;

// parameters
float N = 1000.0f;

bool sum_constraint(float x, float y, float z)
{
   float sum = x + y + z;
   if (sum == N)
      return true;
   return false;
}

bool less_than_constraint(float x, float y, float z)
{
   if (x >= y)
      return false;
   if (y >= z)
      return false;
   return true;
}

bool pythagorean_constraint(float x, float y, float z)
{
   float x_squared = pow(x, 2);
   float y_squared = pow(y, 2);
   float z_squared = pow(z, 2);
   if (x_squared + y_squared == z_squared)
      return true;
   return false;
}

int main()
{
   for (float x = 0.0f; x < N; ++x)
   {
      for (float y = 0.0f; y < N; ++y)
      {
         for (float z = 0.0f; z < N; ++z)
         {
            if (!sum_constraint(x, y, z))
               continue;
            if (!less_than_constraint(x, y, z))
               continue;
            if (!pythagorean_constraint(x, y, z))
               continue;

            float product = x * y * z;
            cout << "values are: " << x << " " << y << " " << z << " the product is: " << product << endl;
            return 0;
         }
      }
   }

   return 0;
}
