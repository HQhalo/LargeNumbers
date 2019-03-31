#include "QFloat.h"
Qfloat::Qfloat(){
    cell[0] = cell[1] = cell[2] = cell[3] = 0;
}


bool Qfloat::getBit(const unsigned char &index) const{
    return ((cell[3 - index / 32] >> (index % 32)) & 1);
}

void Qfloat::turnBitOn(const unsigned char &index){
    cell[3 - index / 32] |= 1 << (index % 32);
}

void Qfloat::turnBitOff(const unsigned char &index){
    cell[3 - index / 32] &= ~((unsigned int) (1) << (index % 32));
}

void Qfloat::setBit(const unsigned char &index, const bool &value)
{
    if (value) turnBitOn(index);
    else turnBitOff(index);
}

const unsigned int *  Qfloat::converT() const {
	return cell;
}
QInt Qfloat::convert()  const{
	unsigned int a[4] = { 0, 0, 0, (1 << 16) - 1 };

	QInt tmp = QInt((*this).converT());
	QInt mask = QInt(a);
	mask = mask << ((32 * 3) + 16);
	tmp = tmp & (~mask);
	
	if ((*this).getExponent() != 0)
		tmp.setBit(127 - 16 + 1 , 1);
	return tmp;
}

unsigned int  Qfloat::getExponent() const {
	Qfloat tmp = *this;
	tmp.turnBitOff(127);
	unsigned int ans = tmp.cell[0];
	ans = ans >> 16;
	return ans;
}
void Qfloat::setExponent(unsigned int Ex) {
	unsigned int tmp = ((unsigned int)1 << 15) - 1;
	tmp = tmp << 16;
	cell[0] &= (~tmp);
	cell[0] = cell[0] | (Ex << 16);
}



void Qfloat::scanQfloat(Qfloat &QF) {
	std::string s;
	std::cin >> s;
	bool isNegative = false;
	if (s[0] == '-')
	{
		isNegative = true;
		s.erase(0, 1);
	}
	std::string a ="", b= "";
	bool haveDot = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.') {
			haveDot = true;
			continue;
		}
		if (haveDot)
			b += s[i];
		else
			a += s[i];
	}
	unsigned int Ex = (1 << 14) -1;
	if (a == "")
		a = b[0],
		b.erase(0, 1),
		Ex--;
	while (a.size() >= 2) {
		b = a[a.size() - 1]+ b  ;
		a.erase(a.size() - 1, 1);
		Ex++;
	}

	QInt tmp ;
	a = a + b;
	while (a.size() != 1 && a[0] == '0')
	{
		a.erase(0, 1);
		Ex--;
	}
		
	for (int i = 0; i < a.size(); i++) {
		tmp.setBit(127 - i, a[i] - '0');
	}

	//tmp.PrintQInt() ;
	//std::cout << "\n";
	while (!tmp.getBit(127))
		tmp = tmp << 1;
	tmp = tmp >> 15;
	for (int i = 0; i < 32 * 3 + 16; i++) {
		QF.setBit(i, tmp.getBit(i));
		//std::cout <<QF.getBit(i);
	}

	//std::cout << "???";
	QF.setExponent(Ex );
	QF.setBit(127, isNegative);
	
}
void Qfloat::PrintQfloat(Qfloat x) {
	int Ex = x.getExponent();
	std::string persent = "";

	if (Ex == 0)
		persent = "0.";
	else
		persent = "1.";

	if (x.getBit(127))
		persent = "-" + persent;
	
	for (int i = 32 * 3 + 16 - 1; i >= 0; i--)
		persent += x.getBit(i) + (int)'0';
	
	while (persent[persent.size() - 1] == '0')
		persent.erase(persent.size() - 1, 1);

	std::cout << persent << "x2^" << Ex - ((1<<14)-1);
}

Qfloat Qfloat::operator * (Qfloat const & other) {

	if (this->isZero() || other.isZero()) {
		return Qfloat();
	}


	unsigned int Ex1 = getExponent();
	unsigned int Ex2 = other.getExponent();
	if (Ex1 == 0)
		Ex1++;
	if (Ex2 == 0)
		Ex2++;
	int Ex = Ex1 + Ex2 - (1 << 14) + 1;

	QInt Sig1 = this->convert();
	QInt Sig2 = other.convert();
	
	Sig1 = Sig1 << 14;
	Sig2 = Sig2 << 14;
	/*Sig1.PrintQInt();
	std:: cout << "\n"; 
	Sig2.PrintQInt();
	std::cout << "\n";*/
	
	if (Sig1 < Sig2) {
		QInt tmp;
		tmp = Sig1;
		Sig1 = Sig2;
		Sig2 = tmp;
	}

	QInt ans;
	for (int i = 0; i < 32 * 3 + 16; i++) {
		if (Sig2.getBit(127-1- i)) {
			ans = ans + (Sig1 >> i);
		}
	}
	//ans.PrintQInt();
	//std::cout << "\n";
	if (ans.getBit(127)) {
		Ex++;
		ans = ans >> 1;
	}	else
	for (int i = 0; i < 32 * 3 + 16; i++) {
		if (ans.getBit(127-1))
			break;
		ans << 1;
		Ex--;
		if (Ex == 0)
			break;
	}

	Qfloat res = Qfloat();
	res.setExponent(Ex);
	
	res.setBit(127, this->getBit(127) != other.getBit(127));

	for (int i = 1; i <= 32 * 3 + 16; i++)
		res.setBit(32 * 3 + 16 - i, ans.getBit(127 - 1- i));

	return res;
}


Qfloat Qfloat::operator + (Qfloat const & other)
{
     Qfloat re;

    QInt number1 = this->convert();
    QInt number2 = other.convert();
    QInt numberRe;
	QInt zero;
    int exponent1 = this->getExponent();
    int exponent2 = other.getExponent();
    int exponent = 0 ;

    bool sign1 = this->getBit(127);
    bool sign2 = other.getBit(127);
    bool sign = true;

	if( exponent1 == 0 && number1 == zero)
	{
		return other;
	}
	
	if( exponent2 == 0 && number2 == zero)
	{
		return *this;
	}
    if(exponent1 > exponent2)
    {
        int shift = exponent1- exponent2;
        number2 = number2 >> shift ;
        exponent2 = exponent1 ;
		if(number2 == zero )
		{
			return *this;
		}
    }

    if(exponent1 < exponent2)
    {
        int shift = exponent2- exponent1;
        number1 = number1 >> shift ;
        exponent1 = exponent2 ;
		if(number1 == zero )
		{
			return other;
		}
    }
    exponent = exponent1;
     
    if(sign1 == sign2)
    {
        numberRe= number1 + number2;
        sign = sign1;
		
        if(numberRe.getBit(113) == true)
        {
            numberRe = numberRe >> 1;
            exponent ++ ;
        }
		
    }
    else
    {
		numberRe = (number1 > number2) ? (number1 - number2) : (number2 - number1);

		sign = (number1 > number2) ? sign1 : sign2;

		for (int i = 112; i >= 0; i--)
		{
			if (numberRe.getBit(112) == true)
				break;
			numberRe = numberRe << 1;
			exponent--;
		}
		
    }

	if(numberRe == zero )
	{
		exponent = 0;
		sign = 0;
	}
	//numberRe.PrintQInt();

    re.setBit(127,sign);
    re.setExponent(exponent);
    
	for(int i=0 ; i < 112 ; i++)
	{
		re.setBit(i, numberRe.getBit(i) ); 
	}

	return re;
}

Qfloat Qfloat::operator - (Qfloat const & other)
{
	Qfloat temp = other;
	temp.setBit( 127 , ! temp.getBit(127) );

	return *this + temp;
}

Qfloat Qfloat::operator / (const Qfloat &other)
{
	Qfloat result;
	//Calc exponent
	unsigned int exponent = (1 << 14) - 1 + getExponent() - other.getExponent();
	//A helping hand - QInt
	QInt a = convert();
	QInt b = other.convert();
	QInt c;


	unsigned int count = 0;

	for (int i = 0; i < 113; i++)
	{		
		c = c << 1;
		c = (c + (a / b)) >> count;
		a = a % b;
		a = a << 1;
		//divine by unformal one
		QInt limit = QInt("1");
		limit = limit << (i + 1);
		while (c >= limit)
		{
			c = c >> 1;
			count++;
			exponent++;
		}
	}
	//Adjust exponent for more precise result
	while ((exponent > 0) && (c.getBit(112) == false))
	{
		c = c << 1;
		c = c + (a / b);
		a = a % b;
		a = a << 1;
		exponent--;		
	}
	//Transfer data to Qfloat result
	result.cell[3] = c.cell[3];
	result.cell[2] = c.cell[2];
	result.cell[1] = c.cell[1];
	result.cell[0] = c.cell[0];
	//Sign and Exponent
	result.setExponent(exponent);
	result.setBit(127, getBit(127) ^ other.getBit(127));

	return result;
}

Qfloat Qfloat::operator << (const int &n)
{
    Qfloat temp = *this;
    
    for( unsigned char i = 127 ; i >= n ; i--)
    {
        if(temp.getBit(i-n))
            temp.turnBitOn(i);
        else 
            temp.turnBitOff(i);
    }
    for(unsigned char i=0;i<n;i++)
    {
        temp.turnBitOff(i);
    }
    return temp;

}

Qfloat Qfloat::operator >> (const int &n)
{
    Qfloat temp= *this;
    for( unsigned char i = 0 ; i < 128-n ; i++)
    {
        if(temp.getBit(i+n))
            temp.turnBitOn(i);
        else 
            temp.turnBitOff(i);
    }
    for(unsigned char i=128 - n ; i < 128 ;i++)
    {
        temp.turnBitOff(i);
    }
    return temp;
}

void Qfloat::pushOut(BigNum &a, unsigned int &exponent)
{
	unsigned int length = a.data.length();

	while ((a.data.length() <= length) && (exponent > 0)) 
	{
		a.doubleValue();
		exponent--;
	}

	for (int i = 0; i < 112; i++)
		a.doubleValue();

	a.data.erase(a.data.length() - length, length);
}

void Qfloat::getRidOfReal(BigNum &a, const unsigned int &count)
{
	unsigned int length = a.data.length();

	for (unsigned int i = 0; i < count; i++) a.doubleValue();

	a.data.erase(a.data.length() - length, length);
}


Qfloat Qfloat::decToBin(std::string str)
{
	
	bool isNegative = false;

	//store the sign
	if (str[0] == '-')
	{
		str.erase(0, 1);
		isNegative = true;
	}

	// add "." and "0"
	if (str.find('.') == -1)
		str = str + ".0";
	Qfloat result;
	if (str == "0.0") return result;

	//Where is the dot?
	int index = str.find('.');
	
	
	BigNum integer(str.substr(0, index));//integer digits
	while (integer.data[0] == '0') integer.data.erase(0, 1);
	BigNum real(str.substr(index + 1));  //real digits
	
	//exponent in be-ass
	unsigned int exponent = (1 << 14) - 1;
	index = -1;
	
	//proceed the integer digit
	while (!integer.isEmpty())
	{
		if (index == 112)
		{
			exponent++;
			result << 1;
		} else index++;

		result.setBit(index, integer.divineByTwo());
	}

	//push left integer digits then proceed real digits
	if ((index < 112) && (index != -1))
	{
		result = result << (112 - index);
		exponent += index;
		index = 112 - index;
		//convert after .dot
		result.getRidOfReal(real, index);
		for (int i = 0; i < index; i++) result.setBit(i, real.divineByTwo());
	} 
	else if (index == -1)//there is no integer part
	{
		result.pushOut(real, exponent); //"result." just be formal
		for (int i = 0; i < 113; i++) result.setBit(i, real.divineByTwo());	
	}
	//else the integer is too large, so sacrifice the preciseness

	result.setExponent(exponent);

	result.setBit(127, isNegative);
	return result;
}


 std::string Qfloat::binToDec(Qfloat x) {
	 std::string s = "1";
	 int sl = 50;
	 for (int i = 0; i < sl; i++)
		 s = s + "0";

	 BigNum a = BigNum(s);
	 BigNum b = BigNum(s);

	 if (x.getExponent() == 0)
		 b = BigNum("0");

	 
	 
	 for (int i = 32 * 3 + 16 - 1; i >= 0; i--) {
		 a.divineByTwo();
		 if (x.getBit(i))
			 b = b + a;
	 }
	 int Ex = x.getExponent() - ((1 << 14 )-1);
	 
	 while (Ex > 0) {
		 b = b + b;

		 Ex--;
	 }
	 while (Ex < 0) {
		 b.divineByTwo();
		 Ex++;
		 
	 }


	 while (b.data.size() < sl + 1)
		 b.data = "0" + b.data;
	 
	 bool isNeedToFix = false;

	 int pos = 33;
	 /*
	 for (int i = 0; i < pos; i++)
		 std::cout << "1";
	 std::cout <<"\n";
	 std::cout << b.data << "\n";
	 */

	 for (int i = pos; i < b.data.size(); i++)
		 
		 if (b.data[i] != '0')
		 {
			 isNeedToFix = true;
		 }

	 if (isNeedToFix) {
		 std::string add = "1";
		 for (int i = pos; i < b.data.size(); i++) {
			 add = add + "0";
			 b.data[i] = '0';
		 }
		 b = b + add;
	 }
		 
	 
	 

	 std::string ans = "";
	 
	 for (int i = 0;  i < (int)b.data.size()-sl; i++) {
		 ans = ans + b.data[i];
		 
	 }
	 
	 ans = ans + ".";
	 for (int i = (int) b.data.size() - sl; i < (int) b.data.size(); i++) {
		 ans = ans + b.data[i];
	 }


	

	 while (ans[ans.size() - 1] == '0')
		 ans.erase(ans.size() - 1, 1);
	 if (ans[ans.size() - 1] == '.')
		 ans.erase(ans.size() - 1, 1);

	 if (x.getBit(127))
		 ans = "-" + ans;
	 return ans;

}


 bool Qfloat::isZero() const {
	 if (getExponent() == 0) {
		 QInt zero;
		 if (zero == convert())
			 return true;
		 return false;
	 }
	 return false;
 }
 void Qfloat::setZero() {
	 Qfloat zero;
	 (*this) = zero;
 }





