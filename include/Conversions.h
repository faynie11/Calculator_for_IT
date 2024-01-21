#pragma once
#include "pch.h"
#include <string>
using std::string;

class Conversions
{
public:
	string DecimalToBinary(string& dec_bin);
	string DecimalToOctal(string& dec_oct);
	string DecimalToHexadecimal(string& dec_num);

	string BinaryToDecimal(string& bin_dec);
	string OctalToDecimal(string& oct_dec);
	string HexadecimalToDecimal(const string& hex_dec);
};
