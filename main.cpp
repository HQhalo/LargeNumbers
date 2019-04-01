#include"QInt.h"
#include "QFloat.h"


void PrintBit(Qfloat a) {
	for (int i = 0; i < 128; i++)
		std::cout << a.getBit(127 - i);
	std::cout << "\n";
}
void TestRange() {

	Qfloat A,B;
	std::string a = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010";
	std::string b = "01000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	for (int i = 0; i < 128; i++)
	{
		A.setBit(127 - i, a[i] - '0');
		B.setBit(127 - i, b[i] - '0');
	}

	 Qfloat temp = B + A;

	 PrintBit(temp); 
	

}
int main(int argc, char const *argv[])
{
	TestRange();
	return 0;
    
}
