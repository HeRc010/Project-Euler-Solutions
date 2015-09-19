#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

// parameters
unsigned line_length = 50;
unsigned N = 13;

// split string according to the given character delimiter
// v1
void split_string(vector<string> &res, const string &s, const char delimiter)
{
   if (s.empty())
      return;

   size_t pos = s.find(delimiter);
   if (pos != string::npos)
   {
      res.push_back(s.substr(0, pos));
      split_string(res, s.substr(pos + 1, s.size()), delimiter);
   }
   else
   {
      res.push_back(s);
   }
}

// v2
vector<string> split_string(const string &s, const char delimiter)
{
   vector<string> res;

   // ensure the string has atleast one character
   if (s.empty())
      return res;

   size_t pos;
   pos = s.find(delimiter);
   if (pos != string::npos)
   {
      // found it
      res.push_back(s.substr(0, pos));

      vector<string> to_add = split_string(s.substr(pos + 1, s.size()), delimiter);
      res.insert(res.end(), to_add.begin(), to_add.end());
   }
   else
   {
      res.push_back(s);
   }

   return res;
}

unsigned char_to_unsigned(char c)
{
   if (c < 48)
      return -1;
   if (c > 57)
      return -1;

   return unsigned(c) - 48;
}

void test_split(const string &line)
{
   // second test
   vector<string> split = split_string(line, '.');

   cout << "Number of substrings: " << split.size() << endl;
   cout << "Values:" << endl;
   for (auto &s : split)
   {
      cout << s << endl;
   }
}

int main()
{
   ifstream in("input.txt");

   string next_line;
   if (!in.is_open())
      return -1;

   stringstream number_ss;
   while (getline(in, next_line))
   {
      number_ss << next_line;
   }

   string number = number_ss.str();

   long max_product = 0;
   for (unsigned i = 0; i < number.size() - N + 1; ++i)
   {
      long product = 1;
      for (unsigned j = 0; j < N; ++j)
      {
         product *= char_to_unsigned(number[i + j]);
      }

      if (product > max_product)
         max_product = product;
   }

   cout << "Max product is: " << max_product << endl;

   in.close();
   return 0;
}
