#include "Trebuchet.h"
#include "iostream"
#include "fstream"

// Test that file can be opened then read input into a string vecotr.
void Trebuchet::readFile(std::vector<std::string>& input, std::string const& fileName)
{

	// initialize fstream
	std::fstream infile;

	// attempt to open file
	infile.open(fileName);

	// if file exists, pull input into string vector
	if (infile)
	{
		// while not at end of file
		while (!infile.eof()) {
			//placeholder string
			std::string x;
			infile >> x;

			// store x in string vector
			input.push_back(x);
		}

		//vecSize = input.size();
		//// TEST: iterate over string vector
		//for (int i = 0; i < vecSize; i++)
		//{
		//	std::cout << i + 1 << ": " << input.at(i) << std::endl;
		//}

		// close file
		infile.close();
	}
	else
	{
		std::cout << "Error, file not found." << std::endl;
	}
}

// read individual chars within a string and return a two digit number based on the ints within them. 
void Trebuchet::convertChartoInt(std::vector<std::string>& input, std::vector<int>& returnVector)
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
