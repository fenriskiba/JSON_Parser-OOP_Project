/*Grant Carroll
  Object Oriented Programming
  Homework 4 - JSON
*/

#include <iostream>
#include <vector>
#include "JSON_Object_Model/JSON_Object_Model.hpp"
#include "StringToJsonParser.hpp"

using namespace std;

vector<string> formatArguments(char* given[], int numOfArgs);

int main(int argc, char* argv[])
{
    JSON_Object* json;
    
    vector<string> listOfArgs;
    listOfArgs = formatArguments(argv, argc);
    
    using iter = std::istreambuf_iterator<char>;
	string s(iter(std::cin), iter());
    
    stringstream jsonStream(s);
    json = (JSON_Object*)ParseJsonObject(jsonStream);
    
    
    
    return 0;
}

//Simple function to reformat argv to be used more easily in the printer
vector<string> formatArguments(char* given[], int numOfArgs)
{
    vector<string> listOfArgs;
    
    for(int i = 1; i < numOfArgs; i++)
    {
        listOfArgs.push_back(given[i]);
    }
    
    return listOfArgs;
}

