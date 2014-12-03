/*Grant Carroll
  Object Oriented Programming
  Homework 4 - JSON
*/

#include "StringToJsonParser.hpp"

using namespace std;

void deleteSpace(std::stringstream& input)
{
    while(std::isspace(input.peek()))
    {
        input.get();
    }
}

std::string getName(std::stringstream& input)
{
    //Start with an empty string
    std::string name = "";
    
    //Remove the first "
    input.get();
    
    //Loop through the string until you hit the other "
    while(input.peek() != '\"')
    {
        if(input.peek() == '\\')
        {
            //Filter through escape characters
            name += input.get();
            switch(input.peek())
            {
                case '\"':
                    name += input.get();
                    break;
                case '\\':
                    name += input.get();
                    break;
                case '/':
                    name += input.get();
                    break;
                case 'b':
                    name += input.get();
                    break;
                case 'f':     
                    name += input.get();
                    break;
                case 'n':     
                    name += input.get();
                    break;
                case 'r':     
                    name += input.get();
                    break;
                case 't':     
                    name += input.get();
                    break;
                case 'u':     
                    name += input.get();//u
                    name += input.get();//hex character 1
                    name += input.get();//hex character 2
                    name += input.get();//hex character 3
                    name += input.get();//hex character 4
                    break;
            }
        }
        else
        {
            name += input.get();
        }
    }
    input.get();
    return name;
}

JSON_Value* ParseJsonObject(std::stringstream& input)
{
    JSON_Object* parsedObject = new JSON_Object();
    
    //Deal with the begining {
    if(input.peek() == '{')
    {
        input.get();
    }
    deleteSpace(input);
    
    //Loop through each character until you find the end }
    while(input.peek() != '}')
    {
        string elementName;
        JSON_Value* elementValue;
        
        deleteSpace(input);
        
        //Collect the name of the element
        if(input.peek() == '\"')
        {
            elementName = getName(input);
        }
        else
        {
            return NULL;
        }
        deleteSpace(input);
        
        //If you see the : between name and value...
        if(input.peek() == ':')
        {
            input.get();
            deleteSpace(input);
            
            //figure out the type of value and send it to be parsed
            if(input.peek() == '{')
            {
                //Object
                elementValue = ParseJsonObject(input);
            }
            else if(input.peek() == '[')
            {
                //Array
                elementValue = ParseJsonArray(input);
            }
            else if(input.peek() == '\"')
            {
                //String
                elementValue = ParseJsonString(input);
            }
            else if(isdigit(input.peek()) || input.peek() == '-')
            {
                //Number
                elementValue = ParseJsonNumber(input);
            }
            else if(input.peek() == 't' || input.peek() == 'f')
            {
                //Bool
                elementValue = ParseJsonBool(input);
            }
            else
            {
                //Null
                elementValue = ParseJsonNull(input);
            }
            
            deleteSpace(input);
            
            //Deal with , between elements
            if(input.peek() == ',')
            {
                input.get();
            }
            
            deleteSpace(input);
            
            parsedObject->emplace(elementName, elementValue);
        }
    }
    
    input.get();
    
    return parsedObject;
}

JSON_Value* ParseJsonArray(std::stringstream& input)
{
    JSON_Array* parsedArray = new JSON_Array();
    
    //Deal with the begining [
    if(input.peek() == '[')
    {
        input.get();
    }
    deleteSpace(input);
    
    //Loop through each character until you find the end ]
    while(input.peek() != ']')
    {
        JSON_Value* elementValue;
        
        deleteSpace(input);
       
        if(input.peek() == ':')
        {
            input.get();
            deleteSpace(input);
            
            //figure out the type of value and send it to be parsed
            if(input.peek() == '{')
            {
                //Object
                elementValue = ParseJsonObject(input);
            }
            else if(input.peek() == '[')
            {
                //Array
                elementValue = ParseJsonArray(input);
            }
            else if(input.peek() == '\"')
            {
                //String
                elementValue = ParseJsonString(input);
            }
            else if(isdigit(input.peek()) || input.peek() == '-')
            {
                //Number
                elementValue = ParseJsonNumber(input);
            }
            else if(input.peek() == 't' || input.peek() == 'f')
            {
                //Bool
                elementValue = ParseJsonBool(input);
            }
            else
            {
                //Null
                elementValue = ParseJsonNull(input);
            }
            
            deleteSpace(input);
            
            //Deal with the , between elements
            if(input.peek() == ',')
            {
                input.get();
            }
            
            deleteSpace(input);
            
            parsedArray->push_back(elementValue);
        }
    }
    
    input.get();
    
    return parsedArray;
}

JSON_Value* ParseJsonString(std::stringstream& input)
{
    JSON_String* jsonString = new JSON_String();
    
    //Start with an empty string
    std::string stringValue = "";
    
    //Remove the first "
    input.get();
    
    //Loop through the string until you hit the other "
    while(input.peek() != '\"')
    {
        if(input.peek() == '\\')
        {
            //Filter through escape characters
            stringValue += input.get();
            switch(input.peek())
            {
                case '\"':
                    stringValue += input.get();
                    break;
                case '\\':
                    stringValue += input.get();
                    break;
                case '/':
                    stringValue += input.get();
                    break;
                case 'b':
                    stringValue += input.get();
                    break;
                case 'f':     
                    stringValue += input.get();
                    break;
                case 'n':     
                    stringValue += input.get();
                    break;
                case 'r':     
                    stringValue += input.get();
                    break;
                case 't':     
                    stringValue += input.get();
                    break;
                case 'u':     
                    stringValue += input.get();//u
                    stringValue += input.get();//hex character 1
                    stringValue += input.get();//hex character 2
                    stringValue += input.get();//hex character 3
                    stringValue += input.get();//hex character 4
                    break;
            }
        }
        else
        {
            stringValue += input.get();
        }
    }
    input.get();
    
    jsonString->value = stringValue;
    
    return jsonString;
}

JSON_Value* ParseJsonNumber(std::stringstream& input){return NULL;}
JSON_Value* ParseJsonBool(std::stringstream& input){return NULL;}
JSON_Value* ParseJsonNull(std::stringstream& input){return NULL;}

