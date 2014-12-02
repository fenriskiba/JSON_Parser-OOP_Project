/*Grant Carroll
  Object Oriented Programming
  Homework 4 - JSON
*/

#ifndef JSON_ARRAY_H
#define JSON_ARRAY_H

#include "JSON_Value.hpp"
#include <vector>


//Object inherits from vector and json value, and will represent a dynamic list of JSON_Values
//Most functionality is inherited from vector, but can also return the string "object" to show it is an object
class JSON_Array : public std::vector<JSON_Value*>, public JSON_Value
{
    public:
        std::string GetType();
};

#endif

