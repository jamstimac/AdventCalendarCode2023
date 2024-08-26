#pragma once
#include <vector>
#include <string>

class FileReader
{

public:
	/// <summary>
	/// Test that file can be opened then read input into a string vector.
	/// Style 0: returns individual strings
	/// Style 1: returns lines from txt files
	/// </summary>
	/// <param name="input"></param>
	/// <param name="fileName"></param>
	static void readFile(std::vector<std::string>& input, std::string const& fileName, int style);
};

