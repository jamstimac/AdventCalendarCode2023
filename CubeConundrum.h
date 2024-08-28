#pragma once
#include <string>

class CubeConundrum
{
public:

	/// <summary>
	/// Returns a two digit string to be converted to an int from two chars
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	static std::string returnTwoDigitNumAsString(char& a, char& b);
	
	/// <summary>
	/// returns a two character string with [game#][t/f] to be parsed whether a game is possible or not.
	/// 1 false return means that game number cannot be added to the game ID total.
	/// </summary>
	/// <param name="gameNum"></param>
	/// <param name="bPossible"></param>
	/// <returns></returns>
	static std::string returnStringofGameNumBool(int& gameNum, bool bPossible);
};

