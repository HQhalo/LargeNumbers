#include"QInt.h"
#include "QFloat.h"

void TestRange() {

	Qfloat A,B;
	std::string a = "0000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000011";
	std::string b = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010";
	for (int i = 0; i < 127; i++)
	{
		A.setBit(127 - i, a[i] - '0');
		std::cout << a[i] - '0';
		B.setBit(127 - i, b[i] - '0');
	}

	std::cout << Qfloat::binToDec(A) << "\n";
	std::cout << Qfloat::binToDec(B) << "\n";
	std::cout << Qfloat::binToDec(A + B) << "\n";
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
