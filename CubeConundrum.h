#pragma once
#include <string>

class CubeConundrum
{
public:

	/// <summary>
	/// Returns a two digit string to be converted to an int from two chars
	/// 
	/// style 0 - twodigit
	/// style 1 - threedigit
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	static std::string returnMulDigitNumAsString(char a, char b, char c='a', int style = 0);


};
