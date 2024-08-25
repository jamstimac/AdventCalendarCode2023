#include "Trebuchet.h"
#include "iostream"
#include "fstream"
#include <vector>

int main()
{
	std::vector<std::string> testInput;

	std::ifstream infile; // file based cin

	

	infile.open("TestInput.txt"); // attempt to open file

	// verify that file opened properly
	// can either check for a null or use .is_open()
	if (infile)
	{
		while (!infile.eof()) {
			std::string x;

			infile >> x;

			testInput.push_back(x);
		}

		for (int i = 0; i < testInput.size(); i++)
		{
			std::cout << i+1 << ": " << testInput.at(i) << std::endl;
		}

		infile.close();
	}
	else
	{
		std::cout << "Error, file not found." << std::endl;
	}

	std::cin.get();
	return 0;
}
