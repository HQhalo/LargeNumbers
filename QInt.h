#pragma once
#include<string>
#define NUMBER_BITS 128

const char hexTable[16] = {'0', '1', '2', '3',
                      '4', '5', '6', '7',
                      '8', '9', 'A', 'B',
                      'C', 'D', 'E', 'F'}

class QInt
{
private:
    /* data */
    unsigned int cell[4];
    
public:
    void scanQInt();
    void PrintQInt();
    
    static QInt decToBin(std::string str);
    static std::string binToDec(QInt x);
    static std::string binToHex(QInt x);
    static std::string decToHex(std::string x);

    QInt & operator + ( QInt const & other);
    QInt & operator - ( QInt const & other);
    QInt & operator * ( QInt const & other);
    QInt & operator / ( QInt const & other);

    QInt & operator = ( QInt const &other);
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
    //QInt operator rol (int n);
   // QInt operator ror (int n);
    

    QInt(/* args */);
    QInt(std::string decNum);
    ~QInt();
};


