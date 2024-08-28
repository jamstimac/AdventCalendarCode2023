#include "iostream"
#include "Trebuchet.h"
#include "FileReader.h"
#include "CubeConundrum.h"
#include <map>


int main()
{
	// vector string
	std::vector<std::string> testInput;
	std::vector<int> parsedStrings;

	size_t vecSize;
	size_t stringSize;

	// editable filename
	std::string const fileName = "CubeTest.txt";

	// read file and save input to vector<string>
	FileReader::readFile(testInput, fileName, 1);

	// white space
	std::cout << std::endl << std::endl;
	//
 
	/// Cube Game --- Problem 2 ///
	// Runs CubeInput.txt or CubeTest.txt 
	// run FileReader::readFile(..., ..., 1)


	/// Sort through data to get easier to manage input

	// stores reduced game strings
	std::vector<std::string> gamesReduced;
	
	// temp string to push back into gamesReduced
	// 0 - game #-1, 1 - color, 2 - amount
	std::string str;

	vecSize = testInput.size();
	for (int i = 0; i < vecSize; i++)
	{
		stringSize = testInput.at(i).size();
		
		// split game #: off i == game num
		for (int j = 8; j < stringSize; j++)
		{
			// if first letter is r but not in green
			if (testInput.at(i).at(j) == 'r' && testInput.at(i).at(j-1) != 'g')
			{
				// store temp string
				str = std::to_string(i);
				str.append(std::string(1, testInput.at(i).at(j)));

				// get more than one digit if possible
				if (testInput.at(i).at(j - 3) != ' ')
				{
					// first then second digit
					str.append(std::string(1, testInput.at(i).at(j - 3)));
					str.append(std::string(1, testInput.at(i).at(j - 2)));
				}
				else
				{
					str.append(std::string(1, testInput.at(i).at(j - 2)));
				}

				// pushback to gamesReduced
				gamesReduced.push_back(str);
			}
			// if first letter is g
			if (testInput.at(i).at(j) == 'g')
			{
				// store temp string
				str = std::to_string(i);
				str.append(std::string(1, testInput.at(i).at(j)));
				
				// get more than one digit if possible
				if (testInput.at(i).at(j - 3) != ' ')
				{
					// first then second digit
					str.append(std::string(1, testInput.at(i).at(j - 3)));
					str.append(std::string(1, testInput.at(i).at(j - 2)));
				}
				else
				{
					str.append(std::string(1, testInput.at(i).at(j - 2)));
				}
				


				// pushback to gamesReduced
				gamesReduced.push_back(str);
			}
			
			// if first letter is b
			if (testInput.at(i).at(j) == 'b')
			{
				// store temp string
				str = std::to_string(i);
				str.append(std::string(1, testInput.at(i).at(j)));

				// get more than one digit if possible
				if (testInput.at(i).at(j - 3) != ' ')
				{
					// first then second digit
					str.append(std::string(1, testInput.at(i).at(j - 3)));
					str.append(std::string(1, testInput.at(i).at(j - 2)));
				}
				else
				{
					str.append(std::string(1, testInput.at(i).at(j - 2)));
				}

				// pushback to gamesReduced
				gamesReduced.push_back(str);
			}

		}
	}
	// TEST: Run gamesreduced size to compare with 
	std::cout << "game, color, amount " << std::endl;
	vecSize = gamesReduced.size();
	for (int i = 0; i < vecSize; i++)
	{
		int currentAmount = 0;
		if (gamesReduced.at(i).length() == 4)
		{
			std::string temp = CubeConundrum::returnTwoDigitNumAsString(gamesReduced.at(i).at(2), gamesReduced.at(i).at(3));

			int currentAmount = std::stoi(temp);
			std::cout << "CurrentAmount = " << currentAmount << std::endl;
		}
		else {
			int currentAmount = gamesReduced.at(i).at(2) - 0 - 48;//conv & adjust for ascii
			std::cout << "CurrentAmount = " << currentAmount << std::endl;
		}

		std::cout << gamesReduced.at(i).at(0)
			<< gamesReduced.at(i).at(1) << currentAmount
			<< std::endl;
	}

	// Test scenario is "possible to have 12 red, 13 green, and 14 blue cubes"
	int totalRdCubes = 12;
	int totalGrCubes = 13;
	int totalBlCubes = 14;

	// adds game ids starting with 1
	int totalGameID = 0;
	std::vector<int> tempGameIDs;
	// iterate over gamesReduced
	for (int i = 0; i < vecSize; i++)
	{
		// format [game#][color][amount] ex: 0g3
		char currentGame = gamesReduced.at(i).at(0) - 0 - 48 + 1;
		char currentColor = gamesReduced.at(i).at(1); 
		int currentAmount = 0;
		if (gamesReduced.at(i).length() == 4) 
		{
			std::string temp = CubeConundrum::returnTwoDigitNumAsString(gamesReduced.at(i).at(2), gamesReduced.at(i).at(3));

			int currentAmount = std::stoi(temp);
			std::cout << "CurrentAmount = " << currentAmount << std::endl;
		}
		else {
			int currentAmount = gamesReduced.at(i).at(2) - 0 - 48;//conv & adjust for ascii
			std::cout << "CurrentAmount = " << currentAmount << std::endl;
		}
		// 
		std::cout << "current game: " << i << std::endl;
		if ((currentAmount != 0) &&
			(currentColor == 'r' && currentAmount <= totalRdCubes) ||
			(currentColor == 'g' && currentAmount <= totalGrCubes) ||
			(currentColor == 'b' && currentAmount <= totalBlCubes))
		{
			std::cout << "current color, amount: " << currentColor << ", " << currentAmount << std::endl;
			tempGameIDs.push_back(currentGame);
		}
	}

	vecSize = tempGameIDs.size();
	for (int i = 0; i < vecSize; i++)
	{

	}

	std::cout << "the answer is... " << totalGameID;


	/// Trebuchet Code --- Problem 1 ///
	// start: read individual chars
	// iterate over testInput string vector
	// Runs testInput.txt or TrebuchetInput.txt 
	// run FileReader::readFile(..., ..., 0)
	//Trebuchet::convertCharStrtoInt(testInput, parsedStrings);

	//Trebuchet::printFinalAdditionParsedStrings(parsedStrings);

	std::cin.get();
	return 0;
}