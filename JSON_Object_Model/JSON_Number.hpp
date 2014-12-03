/*Grant Carroll
  Object Oriented Programming
  Homework 4 - JSON
*/

#ifndef JSON_NUMBER_H
#define JSON_NUMBER_H

#include "JSON_Value.hpp"
#include <cstdlib>
#include <cmath>

//Functions for easy conversion between the JSON number notation and C++ doubles
double JsonToNumber(std::string fullNumber);

//Inherits from JSON_Value so it can be used in the value map or vector of JSON_Object or JSON_Array
class JSON_Number : public JSON_Value
{
    public:
        double value;
        JSON_Number(){}
        JSON_Number(double d) : value(d){}
        JSON_Number(std::string s) : value(JsonToNumber(s)){}
        std::string GetType();
};

#endif

