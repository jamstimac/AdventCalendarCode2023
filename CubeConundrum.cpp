#include "CubeConundrum.h"

std::string CubeConundrum::returnTwoDigitNumAsString(char& a, char& b)
{
	// convert char a into a string
	std::string holderA = std::string(1, a);
	// convert char b into a string
	std::string holderB = std::string(1, b);

	// return concatenated string
	return holderA + holderB;
}

std::string CubeConundrum::returnStringofGameNumBool(int& gameNum, bool bPossible)
{
	// turn game num into a string
	std::string holderNum = std::to_string(gameNum);
	std::string holderBool;
 
	if (bPossible)
	{
		holderBool = "t";
	}
	else
	{
		holderBool = "f";
	}

	return holderNum + holderBool;
}