#pragma once

#include <string>
#include <iostream>

class BigNum
{
private:
    std::string data;

public:
    static int hexToInt(const char&);
    static char intToHex(const int&);
    
    BigNum operator +(BigNum);
    void doubleValue();
    bool divineByTwo();
    bool isEmpty();
    char divineBy16();    
    friend std::ostream& operator << (std::ostream& os, const BigNum& a);
    friend std::istream& operator >> (std::istream& is, BigNum& a);

public:
    BigNum();
    BigNum(const std::string&);
};
