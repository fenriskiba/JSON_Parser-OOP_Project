/*Grant Carroll
  Object Oriented Programming
  Homework 4 - JSON
*/

#ifndef JSON_VALUE_H
#define JSON_VALUE_H

#include <string>

//Purely virtual function that the entire data model will inherit from
class JSON_Value
{
    public:
        JSON_Value(){}
        virtual std::string GetType() = 0;
};

#endif

