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
	std::string a = "00000000000000000000000000000000000000001001001000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	std::string b = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001";
	for (int i = 0; i < 128; i++)
	{
		A.setBit(127 - i, a[i] - '0');
		B.setBit(127 - i, b[i] - '0');
	}

	
	B.setExponent(0);
	std::string s = Qfloat::binToDec(B);
	PrintBit(B);
	std::cout << s;
	

}


int main(int argc, char const *argv[])
{
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
