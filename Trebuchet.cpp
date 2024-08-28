#include "Trebuchet.h"
#include "iostream"
#include "fstream"



// read individual chars within a string and return a two digit number based on the ints within them. 
void Trebuchet::convertCharStrtoInt(std::vector<std::string>& input, std::vector<int>& returnVector)
{
	// holds the two chars
	char hold1 = 0;
	char hold2 = 0;

	// creates the string to be converted into an int
	char holder[3];

	// stores size of vectors for quicker iteration
	int vecSize;
	int stringSize;

	// iterate over testInput string vector
	vecSize = input.size();
	for (int i = 0; i < vecSize; i++)
	{
		// iterate over individual string length
		// requires break to keep from running the entire string
		stringSize = input.at(i).size();
		for (int j = 0; j < stringSize; j++)
		{
			if (isdigit(input.at(i).at(j)))
			{
				hold1 = input.at(i).at(j);
				break;
			}
		}

		// iterate over individual string length backwards 
		// requires break to keep from running the entire string
		for (int j = (stringSize - 1); j >= 0; j--)
		{
			if (isdigit(input.at(i).at(j)))
			{
				hold2 = input.at(i).at(j);
				break;
			}
		}

		// turns chars into a string
		holder[0] = hold1;
		holder[1] = hold2;
		holder[2] = 0;

		// push back ints from new strings
		returnVector.push_back(std::stoi(holder));
	}
	
}
// Add all parsed ints together and cout final result
void Trebuchet::printFinalAdditionParsedStrings(std::vector<int>& parsedInput)
{
	// add each parsed string int together
	int vecSize = parsedInput.size();
	int final = 0;
	for (int i = 0; i < vecSize; i++)
	{
		final += parsedInput.at(i);
	}

	// print final count of parsed strings added together
	std::cout << "The current answer is: " << final << std::endl;
}
