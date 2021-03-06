#pragma once
#include "QInt.h"
#include<string>
#define NUMBER_BITS 128

/*const char hexTable[16] = { '0', '1', '2', '3',
					  '4', '5', '6', '7',
					  '8', '9', 'A', 'B',
 				  'C', 'D', 'E', 'F' };
				  */
class Qfloat
{
public:
	/* data */
	unsigned int cell[4];

public:
	bool getBit(const unsigned char &index) const;
	void turnBitOn(const unsigned char &index);
	void turnBitOff(const unsigned char &index);
	void setBit(const unsigned char &index, const bool &value);
	
	void pushOut(BigNum &a, unsigned int &exponent);
	void getRidOfReal(BigNum &a, const unsigned int &count);
public:
	//nhap so dang nhi phan
	static Qfloat scanQfloat(std::string str);
	static std::string Token(std::string token);
	//in so dang nhi phan
	std::string PrintQfloat(Qfloat x);


	const unsigned int *  converT() const;
	QInt convert() const;

	

	unsigned int  getExponent() const;
	void setExponent(unsigned int Ex);


	static Qfloat decToBin(std::string str);

	//tra ve so dang chuoi string
	static std::string binToDec(Qfloat x);
	static std::string binToHex(Qfloat x);
	static std::string decToHex(std::string x);
	
	static Qfloat infinity(); 
	static Qfloat error();

	Qfloat operator + (Qfloat const & other);
	Qfloat operator - (Qfloat const & other);
	Qfloat operator * (Qfloat const & other);
	Qfloat operator / (Qfloat const & other);


	Qfloat operator << (const int &n);
    Qfloat operator >> (const int &n);

	
	Qfloat(/* args */);
	Qfloat(std::string decNum);
	//~Qfloat();


	bool isZero() const;
	void setZero();

private:
	bool isNan() const ;
	bool isInf() const;
};


