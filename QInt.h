#pragma once
#include<string>
#define NUMBER_BITS 128
using namespace std;
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
    
    friend string decToBin(QInt x);
    friend QInt binToDec(string x);
    friend string binToHex(string x);
    friend string decToHex(QInt x);

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

string decToBin(QInt x);
QInt binToDec(string x);
string binToHex(string x);
string decToHex(QInt x);


