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

		
		int startPoint = 0;
		if (testInput.at(i).at(6) == ':')
		{
			startPoint = 8;
		}
		if (testInput.at(i).at(7) == ':')
		{
			startPoint = 9;
		}
		if (testInput.at(i).at(8) == ':')
		{
			startPoint = 10;
		}

		// split game ###: off i == game num
		for (int j = startPoint; j < stringSize; j++)
		{

			// if first letter is r but not in green
			if (testInput.at(i).at(j) == 'r' && testInput.at(i).at(j - 1) != 'g')
			{
				// store game num
				str = std::to_string(i);
				std::cout << "current index = game num = " << i << std::endl;

				// store color
				str.append(std::string(1, testInput.at(i).at(j)));

				// store amount of cubes
				// get more than one digit if possible
				if (testInput.at(i).at(j - 3) != ' ')
				{
					// first then second digit
					str.append(CubeConundrum::returnMulDigitNumAsString(testInput.at(i).at(j - 3), testInput.at(i).at(j - 2)));
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
				// store game num
				str = std::to_string(i);
				std::cout << "current index = game num = " << i << std::endl;

				// store color
				str.append(std::string(1, testInput.at(i).at(j)));

				// store amount of cubes
				// get more than one digit if possible
				if (testInput.at(i).at(j - 3) != ' ')
				{
					// first then second digit
					str.append(CubeConundrum::returnMulDigitNumAsString(testInput.at(i).at(j - 3), testInput.at(i).at(j - 2)));
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
				// store game num
				str = std::to_string(i);
				std::cout << "current index = game num = " << i << std::endl;

				// store color
				str.append(std::string(1, testInput.at(i).at(j)));

				// store amount of cubes
				// get more than one digit if possible
				if (testInput.at(i).at(j - 3) != ' ')
				{
					// first then second digit
					str.append(CubeConundrum::returnMulDigitNumAsString(testInput.at(i).at(j - 3), testInput.at(i).at(j - 2)));
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

	// Test scenario is "possible to have 12 red, 13 green, and 14 blue cubes"
	int totalRdCubes = 12;
	int totalGrCubes = 13;
	int totalBlCubes = 14;

	// total potential possible games, subtract games as they are proved false
	// uses vecSize from original amount of games
	int totalGameID = 0;
	totalGameID += static_cast<int>(vecSize);
	for (int i = 0; i < vecSize; i++)
	{
		totalGameID += i;
	}
	std::cout << "total possible gameID: " << totalGameID << std::endl << std::endl;

	// TEST:: Do the games reduce properly
	vecSize = gamesReduced.size();
	for (int i = 0; i < vecSize; i++)
	{
		int currentAmount = 0;
		int currentGame = 0;
		std::string currentColor = "";
		std::string temp = "";

		// format [game#][color][amount] ex: 0g3(3)
		if (gamesReduced.at(i).length() == 3)
		{
			currentGame = std::stoi(std::string(1, gamesReduced.at(i).at(0))) + 1; // add one to keep logical first game num
			currentAmount = std::stoi(std::string(1, gamesReduced.at(i).at(2)));//conv to str then int
			currentColor = std::string(1, gamesReduced.at(i).at(1));
			// if length is 4 then number is 2 digits, need to convert differently
		}
		// game number is double digit or amount number is double digit
		else if (gamesReduced.at(i).length() == 4)
		{
			

			// with single digit game number means 
			if (gamesReduced.at(i).at(1) == 'r' ||
				gamesReduced.at(i).at(1) == 'g' ||
				gamesReduced.at(i).at(1) == 'b')
			{
				// game #
				currentGame = std::stoi(std::string(1, gamesReduced.at(i).at(0)));

				// amount
				temp = CubeConundrum::returnMulDigitNumAsString(gamesReduced.at(i).at(2), gamesReduced.at(i).at(3));
				currentAmount = std::stoi(temp);

				// color
				currentColor = std::string(1, gamesReduced.at(i).at(1));
			}

			// with double digit game number
			if (gamesReduced.at(i).at(2) == 'r' ||
				gamesReduced.at(i).at(2) == 'g' ||
				gamesReduced.at(i).at(2) == 'b')
			{
				// game # 10-99
				temp = CubeConundrum::returnMulDigitNumAsString(gamesReduced.at(i).at(0), gamesReduced.at(i).at(1));
				currentGame = std::stoi(temp);

				// amount
				currentAmount = std::stoi(std::string(1, gamesReduced.at(i).at(1)));

				// color
				currentColor = std::string(1, gamesReduced.at(i).at(2));
			}

		}
		// triple digit game number
		else
		{
			// single digit amount
			if (gamesReduced.at(i).length() == 5)
			{
				// game # 100-999
				temp = CubeConundrum::returnMulDigitNumAsString(gamesReduced.at(i).at(0), gamesReduced.at(i).at(1), gamesReduced.at(i).at(2), 1);
				currentGame = std::stoi(temp);

				// amount
				currentAmount = std::stoi(std::string(1, gamesReduced.at(i).at(4)));

				// color
				currentColor = std::string(1, gamesReduced.at(i).at(3));
			}
			// double digit amount
			if (gamesReduced.at(i).length() == 6)
			{
				// game # 100-999
				temp = CubeConundrum::returnMulDigitNumAsString(gamesReduced.at(i).at(0), gamesReduced.at(i).at(1), gamesReduced.at(i).at(2), 1);
				currentGame = std::stoi(temp);

				// amount
				temp = CubeConundrum::returnMulDigitNumAsString(gamesReduced.at(i).at(4), gamesReduced.at(i).at(5));
				currentAmount = std::stoi(temp);

				// color
				currentColor = std::string(1, gamesReduced.at(i).at(3));
			}
		}
		// save current color char as string
		

		std::cout << "[game#][color][amount] :: " << currentGame << currentColor << currentAmount << std::endl;

	}

	// get size of gamesReduced vector
	vecSize = gamesReduced.size();

	// holds previous game int to make sure we're still in same game later
	// initialized to first game
	// changes when games are found impossible
	int previousGame = 1;
	bool haventSubtracted = true;

	// iterate over gamesReduced
	for (int i = 0; i < vecSize; i++)
	{
		// format [game#][color][amount] ex: 0g3(3)
		int currentGame = std::stoi(std::string(1, gamesReduced.at(i).at(0))) + 1; // add one to keep logical first game num

		

		// initialize current amount
		int currentAmount = 0;

		// if length is 4 then number is 2 digits, need to convert differently
		if (gamesReduced.at(i).length() == 4)
		{
			std::string temp = CubeConundrum::returnMulDigitNumAsString(gamesReduced.at(i).at(2), gamesReduced.at(i).at(3));

			currentAmount = std::stoi(temp);
		}
		// else if only single digit
		else 
		{
			currentAmount = std::stoi(std::string(1, gamesReduced.at(i).at(2)));//conv to str then int
		}

		// save current color char as string
		std::string currentColor = std::string(1, gamesReduced.at(i).at(1));
		// 
		std::cout << "current game: " << currentGame << "   ";
		std::cout << "current index: " << i << "   ";
		std::cout << "current color: " << currentColor << "   ";
		std::cout << "current amount: " << currentAmount << std::endl;

		bool exitCondition = false;


		// while parsing games
		while (!exitCondition)
		{

			// if current color and amount are not possible
			if ((currentColor == "r") && (currentAmount > totalRdCubes))
			{
				if (haventSubtracted) {
					// subtract that game num from the total
					std::cout << "subtracting " << currentGame << "from gameTotal" << std::endl;
					totalGameID -= currentGame;
					haventSubtracted = false;
				}
				exitCondition = true;
			}
			// if current color and amount are not possible
			if ((currentColor == "g") && (currentAmount > totalGrCubes))
			{
				if (haventSubtracted) {
					// subtract that game num from the total
					std::cout << "subtracting " << currentGame << "from gameTotal" << std::endl;
					totalGameID -= currentGame;
					haventSubtracted = false;
				}
				else
				{
					std::cout << "already subtracted" << std::endl;
				}
				exitCondition = true;
			}

			// if current color and amount are not possible 
			if ((currentColor == "b") && (currentAmount > totalBlCubes))
			{
				if (haventSubtracted) {
					// subtract that game num from the total
					std::cout << "subtracting " << currentGame << "from gameTotal" << std::endl;
					totalGameID -= currentGame;
					haventSubtracted = false;
				}
				exitCondition = true;
			}

			if ((currentColor == "r") && (currentAmount <= totalRdCubes) ||
				(currentColor == "g") && (currentAmount <= totalGrCubes) ||
				(currentColor == "b") && (currentAmount <= totalBlCubes))
			{
				// exit while, do not change add to game total,
				// this case requires that num and color are possible
				std::cout << " not subtracting " << currentGame << "from gameTotal" << std::endl;
				exitCondition = true;
			}
		}

		if (previousGame != currentGame)
		{
			std::cout << previousGame << " <- previous ... current -> " << currentGame;
			previousGame = currentGame;
			haventSubtracted = true;
		}
		std::cout << std::endl;
	}

	//vecSize = tempGameIDs.size();
	//for (int i = 0; i < vecSize; i++)
	//{

	//}

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