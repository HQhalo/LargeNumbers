#pragma once
#include<string>
#define NUMBER_BITS 128

using namespace std;

const hexTable[16] = {'0', '1', '2', '3',
                      '4', '5', '6', '7',
                      '8', '9', 'A', 'B',
                      'C', 'D', 'E', 'F'}

struct fourInts
{
    /* data */
    unsigned int cell[4];
};

class QInt
{
private:
    /* data */
    fourInts _number;
    
public:
    void scanQInt();
    void PrintQInt();
    
    friend QInt decToBin(string str);
    friend string binToDec(QInt x);
    friend string binToHex(QInt x);
    friend string decToHex(string x);

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
    QInt(string decNum);
    ~QInt();
};

QInt decToBin(string str);
string binToDec(QInt x);
string binToHex(QInt x);
string decToHex(string x);


