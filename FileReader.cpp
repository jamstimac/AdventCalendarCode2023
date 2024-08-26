#include "FileReader.h"
#include "iostream"
#include "fstream"

// Test that file can be opened then read input into a string vecotr.
void FileReader::readFile(std::vector<std::string>& input, std::string const& fileName, int style)
{
	// stores size of vectors for quicker iteration
	int vecSize;

	// initialize fstream
	std::fstream infile;

	// attempt to open file
	infile.open(fileName);

	// if file exists, pull input into string vector
	if (infile)
	{
		// if needing individual strings within lines use style 0
		if (style == 0)
		{
			// while not at end of file
			while (!infile.eof()) 
			{
				//placeholder string
				std::string x;
				infile >> x;

				// store x in string vector
				input.push_back(x);
			}
		}
		// if needing lines of text from a file use style 1
		else if (style == 1)
		{
			// placeholder string for each line
			std::string str;

			// while not at end of file
			while (std::getline(infile, str))
			{
				input.push_back(str);
			}
		}

		vecSize = input.size();
		// TEST: iterate over string vector
		for (int i = 0; i < vecSize; i++)
		{
			std::cout << i + 1 << ": " << input.at(i) << std::endl;
		}

		// close file
		infile.close();
	}
	else
	{
		std::cout << "Error, file not found." << std::endl;
	}
}