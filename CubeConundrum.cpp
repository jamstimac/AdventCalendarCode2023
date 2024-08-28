#include "CubeConundrum.h"

std::string CubeConundrum::returnMulDigitNumAsString(char a, char b, char c, int style)
{
	// store and return strings
	std::string holderA;
	std::string holderB;
	std::string holderC;
	std::string ret = "";

	if (style == 0) {
		// convert char a into a string
		holderA = std::string(1, a);
		// convert char b into a string
		holderB = std::string(1, b);

		// concat string
		ret = holderA + holderB;
	}
	else if (style == 1)
	{
		// convert char a into a string
		holderA = std::string(1, a);
		// convert char b into a string
		holderB = std::string(1, b);
		//convert char c into a string
		holderC = std::string(1, c);

		// concat string
		ret = holderA + holderB + holderC;
	}
	// return concatenated string
	return ret;
}

