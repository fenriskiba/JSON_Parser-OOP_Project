/*Grant Carroll
  Object Oriented Programming
  Homework 4 - JSON
*/

#ifndef STRING_TO_JSON_PARSER_H
#define STRING_TO_JSON_PARSER_H

#include <string>
#include <sstream>
#include <cctype>
#include "JSON_Object_Model/JSON_Object_Model.hpp"

//Set of functions to parse a string (in the form of a stringstream) into a JSON_Value
//stringstream is used for the easy use of .peek() and .get()
  //These functions are used primarily for viewing and removing characters through the
  //recursive layers without adding the complexity of an iterator
void deleteOneChar(std::stringstream& input);

std::string getName(std::stringstream& input);

JSON_Value* ParseJsonObject(std::stringstream& input);
JSON_Value* ParseJsonArray(std::stringstream& input);
JSON_Value* ParseJsonString(std::stringstream& input);
JSON_Value* ParseJsonNumber(std::stringstream& input);
JSON_Value* ParseJsonBool(std::stringstream& input);
JSON_Value* ParseJsonNull(std::stringstream& input);

#endif
