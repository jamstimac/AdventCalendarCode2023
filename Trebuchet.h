#pragma once
#include <vector>
#include <string>

class Trebuchet
{
public:
	/// <summary>
	/// Test that file can be opened then read input into a string vecotr.
	/// </summary>
	/// <param name="input"></param>
	/// <param name="fileName"></param>
	static void readFile(std::vector<std::string>& input, std::string const& fileName);

	/// <summary>
	/// read individual chars within a string and return a two digit number based on the ints within them. 
	/// </summary>
	/// <param name="input"></param>
	/// <param name="returnVector"></param>
	static void convertChartoInt(std::vector<std::string>& input, std::vector<int>& returnVector);

	/// <summary>
	/// Add all parsed ints together and cout final result
	/// </summary>
	/// <param name="parsedInput"></param>
	static void printFinalAdditionParsedStrings(std::vector<int>parsedInput&);

};

