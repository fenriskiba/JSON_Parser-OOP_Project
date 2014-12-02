/*Grant Carroll
  Object Oriented Programming
  Homework 4 - JSON
*/

#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include "JSON_Value.hpp"
#include <map>

//Object inherits from map and json value, and will represent a hash table of JSON_Values
//Most functionality is inherited from map, but can also return the string "object" to show it is an object
class JSON_Object : public std::map<std::string, JSON_Value*>, public JSON_Value
{
    public:
        std::string GetType();
};

#endif

