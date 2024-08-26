#include "iostream"
#include "Trebuchet.h"


int main()
{
	// vector string
	std::vector<std::string> testInput;
	std::vector<int> parsedStrings;

	int vecSize;

	// editable filename
	std::string const fileName = "TrebuchetInput.txt";

	// read file and save input to vector<string>
	Trebuchet::readFile(testInput, fileName);

	// white space
	std::cout << std::endl << std::endl;
	//
 
	// start: read individual chars
	// iterate over testInput string vector
	Trebuchet::convertChartoInt(testInput, parsedStrings);

	// add each parsed string int together
	vecSize = parsedStrings.size();
	int final = 0;
	for (int i = 0; i < vecSize; i++)
	{
		final += parsedStrings.at(i);
	}

	// print final count of parsed strings added together
	std::cout << "The current answer is: " << final << std::endl;

	std::cin.get();
	return 0;
}