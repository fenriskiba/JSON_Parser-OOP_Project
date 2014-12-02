/*Grant Carroll
  Object Oriented Programming
  Homework 4 - JSON
*/

#ifndef JSON_NULL_H
#define JSON_NULL_H

#include "JSON_Value.hpp"

//Inherits from JSON_Value so it can be used in the value map or vector of JSON_Object or JSON_Array
class JSON_Null : public JSON_Value
{
    public:
        std::string GetType();
};

#endif

