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
    cell[3 - index / 32] &= ~(unsigned int (1) << (index % 32));
}

void QInt::setBit(const unsigned char &index, const bool &value)
{
    if (value) turnBitOn(index);
    else turnBitOff(index);
}

