/*Grant Carroll
  Object Oriented Programming
  Homework 4 - JSON
*/

#include <iostream>
#include "JSON_Object_Model/JSON_Object_Model.hpp"
#include "StringToJsonParser.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    JSON_Object* json;
    
    using iter = std::istreambuf_iterator<char>;
	string s(iter(std::cin), iter());
    
    stringstream jsonStream(s);
    
    json = (JSON_Object*)ParseJsonObject(jsonStream);
    
    
    return 0;
}

