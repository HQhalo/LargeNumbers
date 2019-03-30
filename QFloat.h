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
private:
	/* data */
	unsigned int cell[4];

public:
	bool getBit(const unsigned char &index) const;
	void turnBitOn(const unsigned char &index);
	void turnBitOff(const unsigned char &index);
	void setBit(const unsigned char &index, const bool &value);

public:
	static void scanQfloat(Qfloat &x);
	static void PrintQfloat(Qfloat x);


	const unsigned int *  converT() const;
	QInt convert() const;

	

	unsigned int  getExponent() const;
	void setExponent(unsigned int Ex);


	static Qfloat decToBin(std::string str);
	static std::string binToDec(Qfloat x);
	static std::string binToHex(Qfloat x);
	static std::string decToHex(std::string x);

	Qfloat operator + (Qfloat const & other);
	Qfloat operator - (Qfloat const & other);
	Qfloat operator * (Qfloat const & other);
	Qfloat operator / (Qfloat const & other);

	
	Qfloat(/* args */);
	Qfloat(std::string decNum);
	//~Qfloat();
};


