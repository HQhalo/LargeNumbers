#include "BigNum.h"

char BigNum::intToHex(const int &x)
{
    char result;
    switch (x)
    {
        case 0: result = '0'; break;
        case 1: result = '1'; break;
        case 2: result = '2'; break;
        case 3: result = '3'; break;
        case 4: result = '4'; break;
        case 5: result = '5'; break;
        case 6: result = '6'; break;
        case 7: result = '7'; break;
        case 8: result = '8'; break;
        case 9: result = '9'; break;
        case 10: result = 'A'; break;
        case 11: result = 'B'; break;
        case 12: result = 'C'; break;
        case 13: result = 'D'; break;
        case 14: result = 'E'; break;
        case 15: result = 'F'; break;
        default: break;
    }   

    return result;
}

int BigNum::hexToInt(const char &x)
{
    int result;
    switch (x)
    {
        case '0': result = 0; break;
        case '1': result = 1; break;
        case '2': result = 2; break;
        case '3': result = 3; break;
        case '4': result = 4; break;
        case '5': result = 5; break;
        case '6': result = 6; break;
        case '7': result = 7; break;
        case '8': result = 8; break;
        case '9': result = 9; break;
        case 'A': result = 10; break;
        case 'B': result = 11; break;
        case 'C': result = 12; break;
        case 'D': result = 13; break;
        case 'E': result = 14; break;
        case 'F': result = 15; break;
        default: break;
    }   

    return result;
}

bool BigNum::isEmpty(){
    return (data.length() == 0);
}

BigNum::BigNum(){
    data = "";
}

BigNum::BigNum(const std::string& str){
    data = str;
}

BigNum BigNum::operator + (BigNum other)
{
    while (data.length() < other.data.length()) data = '0' + data;
    while (data.length() > other.data.length()) other.data = '0' + other.data;
    
    BigNum result;
    int temp = 0;
    int value;

    for (int i = data.length() - 1; i >= 0; i--)
    {
        value = (data[i] + other.data[i] - 96 + temp);
        temp = value / 10;

        result.data = char(value % 10 + 48) + result.data;
    }

    if (temp > 0) result.data = '1' + result.data;

    return result;
}

void BigNum::doubleValue()
{
    int temp = 0;
    int value;

    for (int i = data.length() - 1; i >= 0; i--)
    {
        value = ((data[i] - 48) << 1) + temp;
        temp = value / 10;

        data[i] = char(value % 10 + 48);        
    }

    if (temp > 0) data = '1' + data;
}

bool BigNum::divineByTwo()
{
    int value;
    int temp = 0;
    int n = data.length();

    for (int i = 0; i < n; i++)
    {
        value = data[i]- 48 + temp  * 10;
        temp = (value & 1);
        data[i] = char((value >> 1) + 48);
    }

    if (data[0] == '0') data.erase(0, 1);

    return temp;
}

char BigNum::divineBy16()
{
    int value;
    int temp = 0;
    int n = data.length();

    for (int i = 0; i < n; i++)
    {
        value = data[i] - 48 + temp * 10;
        temp = value % 16;
        
        data[i] = char(value / 16 + 48);
    }

    while ((data[0] == '0') && (data.length() > 0)) data.erase(0, 1);

    return intToHex(temp);
}

std::ostream& operator << (std::ostream& os, const BigNum& a){
    os << a.data;
    return os;
}

std::istream& operator >> (std::istream& is, BigNum& a){
    is >> a.data;
    return is;
}
