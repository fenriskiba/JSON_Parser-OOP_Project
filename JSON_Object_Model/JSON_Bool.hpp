/*Grant Carroll
  Object Oriented Programming
  Homework 4 - JSON
*/

#ifndef JSON_BOOL_H
#define JSON_BOOL_H

#include "JSON_Value.hpp"

std::string ToLower(std::string s);

//Inherits from JSON_Value so it can be used in the value map or vector of JSON_Object or JSON_Array
class JSON_Bool : public JSON_Value
{
    public:
        bool value;
        JSON_Bool(bool b) : value(b){}
        JSON_Bool(string s) : value(ToLower(s) == "true" ? true : false){}
        std::string GetType();
};

#endif

