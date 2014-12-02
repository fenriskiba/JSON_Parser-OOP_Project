/*Grant Carroll
  Object Oriented Programming
  Homework 4 - JSON
*/

using namespace std;

#include "JSON_Bool.hpp"

std::string JSON_Bool::GetType()
{
    return "bool";
}

std::string ToLower(std::string s)
{
    for(unsigned long long int i = 0; i < s.length(); ++i)
    {
        s[i] = tolower(s[i]);
    }
    
    return s;
}
