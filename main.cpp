#include"QInt.h"
#include "QFloat.h"


void PrintBit(Qfloat a) {
	for (int i = 0; i < 128; i++)
		std::cout << a.getBit(127 - i);
	std::cout << "\n";
}
void TestRange() {

	Qfloat A,B;
	std::string a = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	std::string b = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010";
	for (int i = 0; i < 128; i++)
	{
		A.setBit(127 - i, a[i] - '0');
		B.setBit(127 - i, b[i] - '0');
	}
	A.setExponent((1 << 15) -1 );

	
	B.setExponent(0);
	std::string s = Qfloat::binToDec(A);
	PrintBit(A);
	//std::cin >> s;
	A = Qfloat::decToBin(s);
	/*std::cin >> s;
	B = Qfloat::decToBin(s);
	*/

	//std::cout << Qfloat::binToDec(A) << "\n";
	//std::cout << Qfloat::binToDec(B) << "\n";
	//std::cout << Qfloat::binToDec(B * A) << "\n";
	//PrintBit(B);
	//PrintBit(A);

	//A = B * A;
	PrintBit(A);

	system("pause");
}
int main(int argc, char const *argv[])
{
	TestRange();
	return 0;
    /* code */
	/*std::string s;
	getline(std::cin,s);
	
	std::cout << QInt::getToken(s);
	*/
	

	//std::string s;
	// getline(std::cin,s);
	
	std::cout << QInt::getToken(s);

	/*
	Qfloat x = Qfloat();
	Qfloat::scanQfloat(x);

	std::cout << Qfloat::binToDec(x);

	std::cout << "\n";
	std::cout << "\n";

	Qfloat y = Qfloat();
	Qfloat::scanQfloat(y);
	std::cout << Qfloat::binToDec(y);

	std::cout << "\n";
	std::cout << "\n";
	std::cout << Qfloat::binToDec( x + y);
	*/

	std::cout << "Test dectoBin\n";
	std::cout << "Nhap so thap phan\n";
	std::string s;
	std::cin >> s;
	Qfloat A = Qfloat::decToBin(s);
	

	// std::cout << "Test dectoBin\n";
	// std::cout << "Nhap so thap phan\n";
	// std::cin >> s;
	// Qfloat A = Qfloat::decToBin(s);


	std::cout << "Nhap so thap phan\n";
	std::cin >> s;
 	Qfloat B = Qfloat::decToBin(s);



	std::cout << "ket qua phep *\n";
	std::cout <<Qfloat::binToDec(A / B);

	// std::cout << "ket qua phep *\n";
	// std::cout <<Qfloat::binToDec(A + B);

	/*
	std::cout << "ket qua phep  *  \n";
	std::cout <<Qfloat::binToDec(A * B);
	std::cout << "\n";

	//std::cout << Qfloat::binToDec(A);
	*/
	
	

	/*
	std::string s;
	std::cin >> s;
	QInt a = QInt(s);
	
	std::cin >> s;
	QInt b = QInt(s);

	std::cout << QInt::binToDec(a % b);
	*/
	

	system("pause");
    return 0;
}
