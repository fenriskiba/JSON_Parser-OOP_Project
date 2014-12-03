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
    
    string givenJSON;
    cin >> givenJSON;
    
    stringstream jsonStream(givenJSON);
    
    json = (JSON_Object*)ParseJsonObject(jsonStream);
    
    
    return 0;
}

