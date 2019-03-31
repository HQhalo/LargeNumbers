#include"QInt.h"
#include "QFloat.h"
int main(int argc, char const *argv[])
{
    /* code */
	std::string s;
	/*
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
	
	*/

	std::cout << "Test dectoBin\n";
	std::cout << "Nhap so thap phan\n";
	std::cin >> s;
	Qfloat A = Qfloat::decToBin(s);
	

	std::cout << "Nhap so thap phan\n";
	std::cin >> s;
	Qfloat B = Qfloat::decToBin(s);


<<<<<<< HEAD
	std::cout << "ket qua phep *\n";
	std::cout <<Qfloat::binToDec(A + B);

=======
	std::cout << "ket qua phep  *  \n";
	std::cout <<Qfloat::binToDec(A * B);
	std::cout << "\n";
>>>>>>> tungtp_branch
	//std::cout << Qfloat::binToDec(A);
	
	
	

	/*
	std::cin >> s;
	QInt a = QInt(s);
	
	std::cin >> s;
	QInt b = QInt(s);

	std::cout << QInt::binToDec(a / b);

	*/

	system("pause");
    return 0;
}
