#include"QInt.h"
#include "QFloat.h"
#include <fstream>
using namespace std;


template
<class T> void PrintBit(T a) {
	for (int i = 0; i < 128; i++)
		std::cout << a.getBit(127 - i);
	std::cout << "\n";
}
void TestRange() {

	Qfloat A,B;
	std::string a = "0.0000000000000000000000000000007888609052210118054117285652827862296732064351090230047702789306640625";
	std::string b = "01111111111111100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010";
	for (int i = 0; i < 128; i++)
	{
		A.setBit(127 - i, 0);
		B.setBit(127 - i, b[i] - '0');
	}
	
	std::string s;
	//std::cin >> s;
	B.setExponent(0);
	A = Qfloat::decToBin(a);
	std::cout << A.PrintQfloat(A);
	//std::cout << Qfloat::binToDec(B / A);
	//A = Qfloat::decToBin(s);
	//PrintBit(A);
	//std::string s = Qfloat::binToDec(A);
	//PrintBit(A);
	//std::cin >> s;
	//A = Qfloat::decToBin(s);

	//std::cout << B.binToDec(B);
	
	A.setExponent( (1 << 14)  - 1+  (1<<14) - 1);
	//B.setExponent(1 << 14 + 1 << 14);
//	std::string s = Qfloat::binToDec(A);
	//std::cout << s << "\n";
	
	system("pause");
}

void TestToken() {
	std::string s = "10 1 + 210624583337114373395836055367340864637790190801098222508621955071";
	std::cout <<QInt::getToken(s);
	system("pause");
}
	


int main(int argc, char const *argv[])
{
	TestRange();
	return 0 ;
	fstream input ;
	ofstream output;

	if(argc == 4)
	{
		string temp="";
		
		input.open(argv[1]);
		output.open(argv[2]);
		if (input.is_open())
  		{
			
			if(argv[3][0] == '1')
			{

				while(getline(input,temp))
				{
					cout<<temp;
					output<< QInt::getToken(temp)<<"\n";
				}
				
			}
			else if(argv[3][0] =='2')
			{
				while(getline(input,temp))
				{
					output<< Qfloat::Token(temp);
				}
			}
		

		}
	}

	input.close();
	output.close();
	return 0;
    
}
