#include "QInt.h"

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

QInt QInt::operator - ()
{
    cell[0] = !cell[0];
    cell[1] = !cell[1];
    cell[2] = !cell[2];
    cell[3] = !cell[3];
    for (int i = 3; (++cell[i] == 0) && (i >= 0); i--);
}

