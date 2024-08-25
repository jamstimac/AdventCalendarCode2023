#include "Trebuchet.h"

int main()
{
	// vector string
	std::vector<std::string> testInput;
	std::vector<char> parsedStrings;
	
	// editable filename
	std::string fileName = "TestInput.txt";

	// read file
	Trebuchet::readFile(testInput, fileName);

	// 
	std::cout << std::endl << std::endl;
	//
 
	// FIXME: doesn't save input to testInput
	// start: read individual chars
	// iterate over testInput string vector
	for (int i = 0; i < testInput.size(); i++)
	{
		// iterate over individual string length
		for (int j = 0; j < testInput.at(i).size(); j++)
		{
			std::cout << "saved char from " << i << ". in string at " << j << ": " << testInput.at(i).at(j) << std::endl;
			parsedStrings.push_back(testInput.at(i).at(j));
		}
	}

	std::cin.get();
	return 0;
}