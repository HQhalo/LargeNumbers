#pragma once
#include<string>
#define NUMBER_BITS 128

const char hexTable[16] = {'0', '1', '2', '3',
                      '4', '5', '6', '7',
                      '8', '9', 'A', 'B',
                      'C', 'D', 'E', 'F'};


class QInt
{
private:
    /* data */
    unsigned int cell[4];
    
public:
    static QInt decToBin(std::string str);
    static std::string binToDec(QInt x);
    static std::string binToHex(QInt x);
    static std::string decToHex(std::string x);    

private:
    bool getBit(const unsigned char &index);
    void turnBitOn(const unsigned char &index);
    void turnBitOff(const unsigned char &index);

public:
    QInt operator -();  
    QInt(/* args */);
};
