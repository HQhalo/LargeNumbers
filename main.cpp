#include"QInt.h"
#include "QFloat.h"

template
<class T> void PrintBit(T a) {
	for (int i = 0; i < 128; i++)
		std::cout << a.getBit(127 - i);
	std::cout << "\n";
}
void TestRange() {

	Qfloat A,B;
	std::string a = "00000000000000000000000000000000000000001001001000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	std::string b = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010";
	for (int i = 0; i < 128; i++)
	{
		A.setBit(127 - i, a[i] - '0');
		B.setBit(127 - i, b[i] - '0');
	}
	A.setExponent((1 << 15) -2 );

	
	B.setExponent(0);
	std::string s = Qfloat::binToDec(A);
	PrintBit(A);
	//std::cin >> s;
	//A = Qfloat::decToBin(s);
	/*std::cin >> s;
	B = Qfloat::decToBin(s);
	*/

	//std::cout << Qfloat::binToDec(A) << "\n";
	//std::cout << Qfloat::binToDec(B) << "\n";
	//std::cout << Qfloat::binToDec(B / A) << "\n";
	//PrintBit(B);
	//PrintBit(A);

	//A = B / A;
	//PrintBit(A);

	system("pause");
}
void TestQInt() {
	QInt A, B;
	std::string a = "0000000000000000000000000100010010000000000000000000000000000000000000000000000000000000000000000000000000000000000001001010000";
	std::string b = "00000000000101001000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000010000000000010";
	for (int i = 0; i < 128; i++)
	{
		A.setBit(127 - i, (a[i] - '0' ));
		B.setBit(127 - i, b[i] - '0');
	}
	

	std::string s = QInt::binToDec(A);
	//std::cout << s << "\n";
	//PrintBit(A);
	//PrintBit(B);
	//PrintBit(A + B);
	//std::cout << QInt::binToDec(A) << "\n";
	//std::cout << QInt::binToDec(B) << "\n";
	//std::cout << QInt::binToDec(B / A) << "\n";


	std::cin >> s;
	A = QInt::hexToBin(s);

	std::cin >> s;
	B = QInt::hexToBin(s);

	std::cout << QInt::binToHex(A + B);

	//std::cin >> s;
	//A = QInt::decToBin(s);
	/*std::cin >> s;
	B = Qfloat::decToBin(s);
	*/

	system("pause");
}
int main(int argc, char const *argv[])
{
	TestRange();
	//TestQInt();
	return 0;
    /* code */
	/*std::string s;
	getline(std::cin,s);
	
	std::cout << QInt::getToken(s);
	*/
	

	//std::string s;
	// getline(std::cin,s);
	
	// std::cout << QInt::getToken(s);

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
