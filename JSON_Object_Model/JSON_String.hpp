/*Grant Carroll
  Object Oriented Programming
  Homework 4 - JSON
*/

#ifndef JSON_STRING_H
#define JSON_STRING_H

#include "JSON_Value.hpp"

//Inherits from JSON_Value so it can be used in the value map or vector of JSON_Object or JSON_Array
class JSON_String : public JSON_Value
{
    public:
        std::string value;
        JSON_String(std::string s) : value(s){}
        std::string GetType();
};

#endif

