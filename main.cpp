#include"QInt.h"
#include "QFloat.h"
int main(int argc, char const *argv[])
{
    /* code */
	std::string s;

	//getline(std::cin,s);
	//QInt::decToBin(s).PrintQInt();
	//std::cout << QInt::getToken(s);


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


	/*std::cout << "Test dectoBin\n";
	std::cin >> s;
	Qfloat A = Qfloat::decToBin(s);
	std::cout << (A.getExponent() - (1 << 14) + 1);
	std::cout << "\n";
	A.PrintQfloat(A);
	//std::cout << Qfloat::binToDec(A);
	*/


	system("pause");
    return 0;
}
