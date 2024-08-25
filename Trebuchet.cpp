#include "Trebuchet.h"
#include "iostream"
#include "fstream"

void Trebuchet::readFile(std::vector<std::string> input, std::string fileName)
{
	std::fstream infile;
	infile.open(fileName);// attempt to open file

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

		// TEST: iterate over string vector
		for (int i = 0; i < input.size(); i++)
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
