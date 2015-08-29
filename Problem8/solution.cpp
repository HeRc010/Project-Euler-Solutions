#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// parameters
unsigned N = 0;

// split string according to the given character delimiter
vector<string> split_string(const string &s, const char delimiter)
{
   string to_split = s;
   vector<string> res;

   auto it = find(s.begin(), s.end(), delimiter);
   if (it != s.end())
   {
      // found it
   }

   size_t pos;
   pos = s.find(delimiter);
   if (pos != string::npos)
   {
      // found it
      split_string(string(s.begin(), to_split.begin() + pos), delimiter);
   }
   else
   {

   }

   if (0)
   {

   }
   else
   {

   }

   return res;
}

int main()
{
   ifstream in("input.txt");

   string next_line;
   while (!in.bad())
   {
      cin >> next_line;
      cout << next_line << endl;
   }

   return 0;
}
