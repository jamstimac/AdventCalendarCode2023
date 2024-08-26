#include "iostream"
#include "Trebuchet.h"
#include "FileReader.h"
#include <map>


int main()
{
	// vector string
	std::vector<std::string> testInput;
	std::vector<int> parsedStrings;

	int vecSize;
	int stringSize;

	// editable filename
	std::string const fileName = "CubeTest.txt";

	// read file and save input to vector<string>
	FileReader::readFile(testInput, fileName, 1);

	// white space
	std::cout << std::endl << std::endl;
	//
 
	// Test scenario is "possible to have 12 red, 13 green, and 14 blue cubes"
	int totalRedCubes = 12;
	int totalGrCubes = 13;
	int totalBlCubes = 14;


	// if we want to test multiple, we need to for loop to find specific numbers with specific
	// amounts of cubes. But instead of characters we're looking for strings
	// parse each line into temporary sections?
	//std::vector<std::string> games;

	vecSize = testInput.size();
	for (int i = 0; i < vecSize; i++)
	{
		stringSize = testInput.at(i).size();

		// split game #: off i == game num
		for (int j = 8; j < stringSize; j++)
		{
			// std::cout << "game " << i << ": " << testInput.at(i).at(j);
			// if first letter is r but not in green
			if (testInput.at(i).at(j) == 'r' && testInput.at(i).at(j-1) != 'g')
			{
				// insert num before letter and string
				std::cout << testInput.at(i).at(j);
				std::cout << testInput.at(i).at(j - 2);
				std::cout << std::endl;
				
			}
			// if first letter is g
			if (testInput.at(i).at(j) == 'g')
			{
				// insert num before letter and string
				std::cout << testInput.at(i).at(j);
				std::cout << testInput.at(i).at(j-2);
				std::cout << std::endl;
				
			}
			
			// if first letter is b
			if (testInput.at(i).at(j) == 'b')
			{
				// insert num before letter and string
				std::cout << testInput.at(i).at(j);
				std::cout << testInput.at(i).at(j - 2);
				std::cout << std::endl;
				
			}
			std::cout << std::endl;

		}
		

	}
	

	/// Trebuchet Code --- Problem 1 ///
	// start: read individual chars
	// iterate over testInput string vector
	//Trebuchet::convertChartoInt(testInput, parsedStrings);

	//Trebuchet::printFinalAdditionParsedStrings(parsedStrings);

	std::cin.get();
	return 0;
}