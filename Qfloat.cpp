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
    cell[3 - index / 32] &= ~(unsigned int (1) << (index % 32));
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
	unsigned int a[4] = { 0, 0, 0, (1 << 15) - 1 };

	QInt tmp = QInt((*this).converT());
	QInt mask = QInt(a);
	mask = mask << ((32 * 3) + 16);
	tmp = tmp & (~mask);
	std::cout << "\n";
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
	Sig1.PrintQInt();
	std:: cout << "\n"; 
	Sig2.PrintQInt();
	std::cout << "\n";
	
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
	ans.PrintQInt();
	std::cout << "\n";
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
	
	/*if (Ex < 0) Ex = (1 << 15) - 1;

	if (Ex > (1 << 15 - 1))
		Ex = (1 << 15 - 1), ans = ans & QInt();
		*/

	res.setBit(1, this->getBit(127) != other.getBit(127));

	for (int i = 1; i <= 32 * 3 + 16; i++)
		res.setBit(32 * 3 + 16 - i, ans.getBit(127 - 1- i));

	return res;
}










