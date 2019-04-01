#include"QInt.h"
#include "QFloat.h"
int main(int argc, char const *argv[])
{
	std::string s;
	getline(std::cin,s);
	
	std::cout << QInt::getToken(s);

	
	

	system("pause");
    return 0;
}
