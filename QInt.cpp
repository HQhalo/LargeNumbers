#include "QInt.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////Tam's
QInt::QInt(){
    cell[0] = cell[1] = cell[2] = cell[3] = 0;
}

bool QInt::getBit(const unsigned char &index){
    return ((cell[3 - index / 32] >> (index % 32)) & 1);
}

void QInt::turnBitOn(const unsigned char &index){
    cell[3 - index / 32] |= 1 << (index % 32);
}

void QInt::turnBitOff(const unsigned char &index){
    cell[3 - index / 32] &= !(1 << (index % 32));
}

void QInt::setBit(const unsigned char &index, const bool &value)
{
    if (value) turnBitOn(index);
    else turnBitOff(index);
}

QInt QInt::operator - ()
{
    QInt temp;
    temp.cell[0] = !cell[0];
    temp.cell[1] = !cell[1];
    temp.cell[2] = !cell[2];
    temp.cell[3] = !cell[3];
    for (int i = 3; (++temp.cell[i] == 0) && (i >= 0); i--);
    return temp;
}

QInt::QInt(std::string line)
{
    cell[0] = cell[1] = cell[2] = cell[3] = 0;

    bool isNegative = (line[0] == '-');
    if (isNegative) line.erase(0, 1);

    BigNum temp(line);
    int i = 3;
    int m = 0;

    while (!temp.isEmpty())
    {
        cell[i] += temp.divineByTwo() << (m++);
        if (m == 32)
        {
            m = 0;
            i--;
        }
    }

    if (isNegative) (*this) = -(*this);
}

QInt QInt::decToBin(std::string str){
    return QInt(str);
}

std::string QInt::binToDec(QInt x)
{
    bool isNegative = x.getBit(127);
    if (isNegative) x = -x;

    std::string result = "0";
    std::string temp = "1";

    for (int i = 0; i < 128; i++)
        if (x.getBit(i)) result = result + temp;
    
    if (isNegative) result = '-' + result;

    return result;
}

std::string QInt::binToHex(QInt x)
{
    std::string result = "";

    for (int i = 3; i >= 0; i--)
        for (int j = 0; j < 8; j++)
        {
            result = BigNum::intToHex(x.cell[i] % 16) + result;
            x.cell[i] >> 4;
        }
    
    return result;
}

QInt QInt::hexToBin(const std::string &str)
{
    QInt temp;

    int i = 3;
    int m = 0;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        temp.cell[i] += BigNum::hexToInt(str[i]);
        m += 4;
        if (m == 32)
        {
            m = 0;
            i--;
        } else temp.cell[i] <<= 4;
    }
    
    return temp;
}


std::string QInt::decToHex(std::string x)
{
    QInt temp(x);
    return binToHex(x);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////end

QInt QInt::operator + (QInt const & other) {
	QInt ans = *this;

	unsigned long long tmp = 0;
	tmp += ans.cell[3];
	tmp += other.cell[3];
	ans.cell[3] = tmp % (1 << 32);
	tmp = tmp >> 32;

	tmp += ans.cell[2];
	tmp += other.cell[2];
	ans.cell[2] = tmp % (1 << 32);
	tmp = tmp >> 32;

	tmp += ans.cell[1];
	tmp += other.cell[1];
	ans.cell[1] = tmp % (1 << 32);
	tmp = tmp >> 32;

	tmp += ans.cell[0];
	tmp += other.cell[0];
	ans.cell[0] = tmp % (1 << 32);
	tmp = tmp >> 32;

	return ans;
}

QInt QInt::operator - (QInt const & other) {

	QInt tmp = other;
	tmp = -tmp;
	return (*this) + other;
}

QInt QInt::operator * (QInt const & other) {
	QInt ans;
	for (int i = 3; i >= 0; i--) {
		unsigned long long tmp = 0;
		int pos = i;
		for (int j = 3; j >= 0; j--) {
			if (pos < 0)
				break;

			tmp += unsigned long long(cell[i]) * cell[j] + ans.cell[i];
			ans.cell[i] = tmp % (1 << 32);
			tmp >> 32;

			pos--;
		}
	}
	return ans;
}
QInt QInt::operator / (QInt const & other) {
	QInt tmp = *this;

	QInt de;
	QInt temp2 = other;
	if (temp2 > de) {
		de = other;
		de = -de;
	}
	else
		de = other;

	QInt zero, num;


	if (*this < 0)
		num = QInt("-1");

	for (int i = 0; i < 128; i++) {
		int bit_left = getBit(127);
		tmp << 1;
		num << 1;
		num.setBit(0, bit_left);


		num = num + de;
		if (num < zero) {
			tmp.setBit(0, 0);
			num = num - de;
		}
		else
			tmp.setBit(0, 1);
	}
	return tmp;

}




bool QInt::operator == ( QInt const &other)
{
    for(int i=0;i<4;i++)
    {
        if(this->cell[i]!=other.cell[i])
        {
            return false;
        }

    }
    return true;

}

QInt::~QInt()
{

}

bool QInt::operator < (QInt const &other)
{
	int sign1 = (cell[0] << 31) & 1;
	int sign2 = (other.cell[0] << 31) & 1;

	if (sign1 == 0)
	{
		if (sign2 == 1)
		{
			return false;
		}
		for (int i = 0; i < 4; i++)
		{
			if (cell[i] < other.cell[i])
				return true;
		}
		return false;
	}
	if (sign1 == 1)
	{
		if (sign2 == 0)
		{
			return true;
		}

		QInt temp = -*this;
		QInt temp2 = other;
		temp2 = -temp;

		for (int i = 0; i < 4; i++)
		{
			if (temp.cell[i] > temp2.cell[i])
				return true;
		}
		return false;
	}

}
bool QInt::operator >= (QInt const &other)
{
	return !(*this < other);
}
bool QInt::operator <= (QInt const &other)
{
	return (*this < other) || (*this == other);
}
bool QInt::operator > (QInt const &other)
{
	return !(*this <= other);
}



QInt QInt::operator & (QInt const &other)
{
	QInt re = QInt();
	for (int i = 0; i < 4; i++)
	{
		re.cell[i] = this->cell[i] & other.cell[i];
	}

	return re;
}


QInt QInt::operator | (QInt const &other)
{
	QInt re;
	for (int i = 0; i < 4; i++)
	{
		re.cell[i] = this->cell[i] | other.cell[i];
	}

	return re;
}


QInt QInt::operator ^ (QInt const &other)
{
	QInt re;
	for (int i = 0; i < 4; i++)
	{
		re.cell[i] = this->cell[i] ^ other.cell[i];
	}

	return re;
}


QInt QInt::operator ~ ()
{
	QInt re;
	for (int i = 0; i < 4; i++)
	{
		re.cell[i] = ~this->cell[i];
	}

	return re;
}

bool QInt::operator == (const long long & other)
{
	QInt temp(std::to_string(other));

	return *this == temp;
}

bool QInt::operator < (const long long & other)
{
	QInt temp(std::to_string(other));

	return *this < temp;
}
bool QInt::operator >= (const long long & other)
{
	QInt temp(std::to_string(other));
	return *this >= temp;
}
bool QInt::operator > (const long long & other)
{
	QInt temp(std::to_string(other));

	return *this > temp;
}

bool QInt::operator <= (const long long & other)
{
	QInt temp(std::to_string(other));

	return *this <= temp;
}

QInt QInt::operator & (const long long& other)
{
	QInt temp(std::to_string(other));

	return *this & temp;
}

QInt QInt::operator | (const long long& other)
{
	QInt temp(std::to_string(other));

	return *this | temp;
}

QInt QInt::operator ^ (const long long& other)
{
	QInt temp(std::to_string(other));

	return *this ^ temp;
}

QInt& QInt::operator = (const long long& other)
{
	QInt temp(std::to_string(other));
	for (int i = 0; i < 4; i++)
	{
		this->cell[i] = temp.cell[i];
	}
	return *this;
}

QInt QInt::operator << (const int &n)
{

    QInt temp = *this;
    
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

QInt QInt::operator >> (const int &n)
{

    QInt temp= *this;
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

QInt QInt::rol (int n)
{
    return *this << n | *this >> (128 -n);
}

QInt QInt::ror (int n)
{
   return *this >> n | *this << (128-n);
}

std::string QInt::getToken(std::string Tokens) {
	std::vector<std::string> Token;

	std::string tmp = 0;
	for (int i = 0; i < Tokens.size(); i++) {
		if (Tokens[i] == ' ')
			continue;

		tmp += Tokens[i];

		if (i == Tokens.size() - 1 || Tokens[i + 1] == '=') {
			Token.push_back(tmp);
			tmp = "";
		}
	}

	if (Token.size() == 4) {
		QInt a;
		QInt b;

		if (Token[0] == "2") {



		}
		if (Token[0] == "10") {



		}
		if (Token[0] == "16") {



		}

		if (Token[2] == "+") {



		}
		if (Token[2] == "-") {



		}
		if (Token[2] == "*") {



		}
		if (Token[2] == "/") {



		}
		if (Token[2] == "&") {



		}
		if (Token[2] == "|") {



		}
		if (Token[2] == "^") {



		}
	}
}
