#include "QFloat.h"
Qfloat::Qfloat(){
    cell[0] = cell[1] = cell[2] = cell[3] = 0;
}

bool Qfloat::getBit(const unsigned char &index){
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

QInt Qfloat::convert() {
	return QInt(cell);
}

int  Qfloat::getExponent() const {
	Qfloat tmp = *this;
	tmp.turnBitOff(127);
	int ans = tmp.cell[0];
	ans = ans >> 16;
	return ans;
}
void Qfloat::setExponent(int Ex) {
	unsigned int tmp = ((unsigned int)1 << 15) - 1;
	tmp = tmp << 16;

	(*this).cell[0] &= ~tmp;
	cell[0] += Ex << 16;
}



Qfloat Qfloat::operator * (Qfloat const & other) {
	int Ex1 = getExponent();
	int Ex2 = other.getExponent();
	int Ex = Ex1 + Ex2 - (1 << 16) - 1;

	QInt tmp = ()

	QInt A = (

}










