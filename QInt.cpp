#include"QInt.h"



QInt & operator + ( QInt const & other){
	unsigned long long tmp = 0;
	tmp += *this.cell[3];
	tmp += other.cell[3];
	cell[3] = tmp % (1 << 32);
	tmp = tmp >> 32;

	tmp += *this.cell[2];
	tmp += other.cell[2];
	cell[2] = tmp % (1 << 32);
	tmp = tmp >> 32;

	tmp += *this.cell[1];
	tmp += other.cell[1];
	cell[1] = tmp % (1 << 32);
	tmp = tmp >> 32;

	tmp += *this.cell[0];
	tmp += other.cell[0];
	cell[0] = tmp % (1 << 32);
	tmp = tmp >> 32;
}

QInt & operator - ( QInt const & other){
	QInt tmp = - other;
	return *this + other;
}

QInt & operator * ( QInt const & other){
	QInt ans;
	for (int i = 3; i >= 0; i--)
		unsigned long long tmp = 0;
		int pos = i;
		for (int j = 3; j >= 0; j--){
			if (pos < 0)
				break;

			tmp += unsigned long long (cell[i]) * cell[j] + ans.cell[i];
			ans.cell[i] = tmp % (1 <<32);
			tmp >> 32;

			pos--;
		}
}
QInt & operator / ( QInt const & other){
	QInt tmp = *this;

	QInt de;
	if (other > de) 
		de = -other;
	else 
		de = other;

	QInt zero ,num ;


	if (* < 0)
		num = ("-1");

	for (int i = 0; i < 128; i++){
		int bit_left = getBit(127);
		tmp << 1;
		num << 1;
		num.setBit(0 , bit_left);


		num = num + de;
		if (num < zero){
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

QInt::QInt()
{

}

QInt::~QInt()
{
    
}

bool QInt::operator< ( QInt const &other)
{
    int sign1= (cell[0] << 31) & 1;
    int sign2= (other.cell[0] << 31) & 1;

    if(sign1 == 0)
    { 
        if(sign2 == 1)
        {   
            return false;
        }
        for(int i =0 ; i < 4; i ++)
        {
            if(cell[i] < other.cell[i])
                return true;
        }
        return false;
    }
    if(sign1 == 1)
    {
        if(sign2 == 0)
        {
            return true;
        }

        QInt temp = - *this;
        QInt temp2 = - other;
       
        for(int i =0 ; i < 4; i ++)
        {
            if(temp.cell[i] > temp2.cell[i])
                return true;
        }
        return false;
    }

}
bool QInt::operator >= ( QInt const &other)
{
    return !(*this < other);
}
bool QInt::operator <= ( QInt const &other)
{
    return (*this < other) || (*this == other);
}
bool QInt::operator > ( QInt const &other)
{
    return ! (*this <= other);
}



QInt QInt::operator & ( QInt const &other)
{
    QInt re;
    for(int i = 0 ; i < 4 ; i++)
    {
        re.cell[i]= this->cell[i] & other.cell[i];
    }

    return re;
}


QInt QInt::operator | ( QInt const &other)
{
    QInt re;
    for(int i = 0 ; i < 4 ; i++)
    {
        re.cell[i]= this->cell[i] | other.cell[i];
    }

    return re;
}


QInt QInt::operator ^ ( QInt const &other)
{
    QInt re;
    for(int i = 0 ; i < 4 ; i++)
    {
        re.cell[i]= this->cell[i] ^ other.cell[i];
    }

    return re;
}


QInt QInt::operator ~ ( )
{
    QInt re;
    for(int i = 0 ; i < 4 ; i++)
    {
        re.cell[i]= ~ this->cell[i] ;
    }

    return re;
}

bool QInt::operator == (const long long & other)
{
    QInt temp(std::to_string(other));

    return *this  == temp;  
}

bool QInt::operator < (const long long & other)
{
    QInt temp(std::to_string(other));

    return *this  < temp;  
}
bool QInt::operator >= (const long long & other)
{
    QInt temp(std::to_string(other));
    return *this >= temp;
}
bool QInt::operator > (const long long & other)
{
    QInt temp(std::to_string(other));

    return *this  > temp;  
}

bool QInt::operator <= (const long long & other)
{
    QInt temp(std::to_string(other));

    return *this  <= temp;  
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
    for(int i=0 ;i < 4; i++)
    {
        this->cell[i] = temp.cell[i];
    }
    return *this;
}

QInt QInt::operator << (const int &n)
{
    for( int i = 0 ; i < 128 - n ; i++)
    {
        this->cell[i]
    }
}
