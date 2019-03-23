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
    
    static string decToBin(QInt x);
    static QInt binToDec(string x);
    static string binToHex(string x);
    static string decToHex(QInt x);

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
    
     QInt & operator = (long long other);
    bool operator < (long long other);
    bool operator <= (long long other);
    bool operator > (long long other);
    bool operator >= (long long other);
    bool operator == (long long other);

    QInt operator & ( QInt const &other);
    QInt operator | ( QInt const &other);
    QInt operator ^ ( QInt const &other);
    QInt operator ~ ();

    QInt operator & (long long other);
    QInt operator | (long long other);
    QInt operator ^ (long long other);

    QInt operator << (int n);
    QInt operator >> (int n);
    //QInt operator rol (int n);
   // QInt operator ror (int n);
    

    QInt(/* args */);
    QInt(string decNum);
    ~QInt();
};




