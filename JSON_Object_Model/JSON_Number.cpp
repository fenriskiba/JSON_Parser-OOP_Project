/*Grant Carroll
  Object Oriented Programming
  Homework 4 - JSON
*/

#include "JSON_Number.hpp"

using namespace std;

string JSON_Number::GetType()
{
	return "number";
}

double JsonToNumber(string fullNumber)
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
