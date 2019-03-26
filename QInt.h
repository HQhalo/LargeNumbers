#pragma once
#include<string>
#include <vector>
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
	std::string getToken(std::string Tokens);
    void scanQInt();
    void PrintQInt();

public:
    static QInt decToBin(std::string str);
    static std::string binToDec(QInt x);
    static std::string binToHex(QInt x);
    static QInt hexToBin(const std::string &str);
    static std::string decToHex(std::string x);    

private:
    bool getBit(const unsigned char &index);
    void turnBitOn(const unsigned char &index);
    void turnBitOff(const unsigned char &index);
    void setBit(const unsigned char &index, const bool &value);
	
public:
    QInt operator + ( QInt const & other);
    QInt operator - ( QInt const & other);
	QInt  operator -();
    QInt operator * ( QInt const & other);
    QInt operator / ( QInt const & other);

 
    bool operator < ( QInt const &other);
    bool operator <= ( QInt const &other);
    bool operator > ( QInt const &other);
    bool operator >= ( QInt const &other);
    bool operator == ( QInt const &other);
    
     QInt & operator = (const long long &other);
    bool operator < (const long long &other);
    bool operator <= (const long long &other);
    bool operator > (const long long &other);
    bool operator >= (const long long &other);
    bool operator == (const long long &other);

    QInt operator & ( QInt const &other);
    QInt operator | ( QInt const &other);
    QInt operator ^ ( QInt const &other);
    QInt operator ~ ();

    QInt operator & (const long long& other);
    QInt operator | (const long long& other);
    QInt operator ^ (const long long& other);

    QInt operator << (const int &n);
    QInt operator >> (const int &n);
    QInt  rol (int n);
    QInt  ror (int n);
    

    QInt(/* args */);
    QInt(std::string decNum);
    ~QInt();
};


