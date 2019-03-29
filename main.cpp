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
	Qfloat::PrintQfloat(x);

	std::cout << "\n";

	Qfloat y = Qfloat();
	Qfloat::scanQfloat(y);
	Qfloat::PrintQfloat(y);

	std::cout << "\n";
	Qfloat::PrintQfloat(x*y);

	system("pause");
    return 0;
}
