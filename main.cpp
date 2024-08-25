#include "Trebuchet.h"

int main()
{
	// vector string to store input
	std::vector<std::string> testInput;
	
	// editable filename
	std::string fileName = "TestInput.txt";

	// read file
	Trebuchet::readFile(testInput, fileName);



	std::cin.get();
	return 0;
}