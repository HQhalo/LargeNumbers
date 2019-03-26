#include"QInt.h"

int main(int argc, char const *argv[])
{
    /* code */
	std::string s;

	getline(std::cin,s);
	//QInt::decToBin(s).PrintQInt();
	std::cout << QInt::getToken(s);
	system("pause");
    return 0;
}
