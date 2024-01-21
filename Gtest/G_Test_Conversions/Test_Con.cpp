#include "pch.h"
#include "Test_Con.h"
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout, std::cin, std::endl;

string Test_Con::DecimalToHexadecimal(string& dec_nu)
{
    int dec_num = std::stoi(dec_nu);

    string hexa_num;

    while (dec_num != 0) {

        int reszta = 0;
        char znak;
        // reszta
        reszta = dec_num % 16;

        if (reszta < 10) {
            znak = reszta + 48; //Ascii dla 0 - 9
        }
        else {
            znak = reszta + 55; // Ascii dla A - F
        }

        hexa_num += znak;
        dec_num = dec_num / 16;
    }
    //petla ktora odwraca nam stringa
    int i = 0, j = hexa_num.size() - 1;
    while (i <= j)
    {
        std::swap(hexa_num[i], hexa_num[j]);
        i++;
        j--;
    }
    return hexa_num;
}

string Test_Con::HexadecimalToDecimal(const string& hex_dec)
{
    int base = 1;
    int dec_val = 0;

    // Wyciaga ostatni znak jako cyfre
    for (int i = hex_dec.size() - 1; i >= 0; i--) {
        //jesli znak lezy pomiedzy 0 a 9
        //wyciaga z ascii odpowiedni numer
        //48 w ascii odpowiada '0'
        if (hex_dec[i] >= '0' && hex_dec[i] <= '9') {
            dec_val += (int(hex_dec[i]) - 48) * base;

            base = base * 16;
        }
        // jesli znak miesci sie miedzy A a F, zmienia
        // sie w cyfre 10-15 znowu wyciagajac znak z ascii
        // A - F to 65 - 70
        else if (hex_dec[i] >= 'A' && hex_dec[i] <= 'F') {
            dec_val += (int(hex_dec[i]) - 55) * base;
            base = base * 16;
        }
    }
    string s_dec_num = std::to_string(dec_val);
    return s_dec_num;
}


string Test_Con::DecimalToBinary(string& dec_bi)
{
    int dec_bin = std::stoi(dec_bi);

    vector<int> binaryNum;

    while (dec_bin > 0) {

        binaryNum.push_back(dec_bin % 2);
        dec_bin = dec_bin / 2;
    }

    string s_bin_num;

    for (int j = binaryNum.size() - 1; j >= 0; j--)
        s_bin_num += std::to_string(binaryNum[j]);

    return s_bin_num;
}

string Test_Con::DecimalToOctal(string& dec_oc)
{
    int dec_oct = std::stoi(dec_oc);
    int octalNumber[100];
    int i = 1;
    int j;


    while (dec_oct != 0) {
        octalNumber[i++] = dec_oct % 8;
        dec_oct = dec_oct / 8;
    }

    string s_oct_num;

    for (j = i - 1; j > 0; j--) {
        s_oct_num += std::to_string(octalNumber[j]);
    }

    return s_oct_num;
}

string Test_Con::OctalToDecimal(string& oct_de)
{
    int oct_dec = std::stoi(oct_de);
    int decimalNumber = 0, i = 0;

    // Convert to decimal
    while (oct_dec != 0) {
        decimalNumber += (oct_dec % 10) * pow(8, i);
        ++i;
        oct_dec /= 10;
    }
    string s_dec_num = std::to_string(decimalNumber);

    return s_dec_num;
}

string Test_Con::BinaryToDecimal(string& bin_de)
{
    int bin_dec = std::stoi(bin_de);
    int decimalNumber = 0;
    int i = 0;

    // Convert to decimal
    while (bin_dec != 0) {
        decimalNumber += (bin_dec % 10) * pow(2, i);
        ++i;
        bin_dec /= 10;
    }
    string s_dec_num = std::to_string(decimalNumber);

    return s_dec_num;
}