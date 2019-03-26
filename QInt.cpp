#include"QInt.h"


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
