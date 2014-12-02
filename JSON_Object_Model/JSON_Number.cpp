/*Grant Carroll
  Object Oriented Programming
  Homework 4 - JSON
*/

using namespace std;

#include "JSON_Number.hpp"

std::string JSON_Number::GetType()
{
	return "number";
}

double JsonToNumber(std::string fullNumber)
{
    string baseNumber = "";
    string scientificNotationValue = "";
    double finalNumber;
    bool foundScientific = false;
    
    for(unsigned long long int i = 0; i < fullNumber.length(); i++)
    {
        if(fullNumber[i] == 'e' || fullNumber[i] == 'E')
        {
            foundScientific = true;
        }
        
        if(!foundScientific)
        {
            baseNumber += fullNumber[i];
        }
        else
        {
            if(fullNumber[i] != 'e' || fullNumber[i] != 'E')
            {
                scientificNotationValue += fullNumber[i];
            }
        }
    }
    
    finalNumber = stod(baseNumber);
    
    if(foundScientific)
    {
        finalNumber *= pow(10, stod(scientificNotationValue));
    }
    
    return finalNumber;
}
