#include"QInt.h"


bool QInt::operator == ( QInt const &other)
{
    for(int i=0;i<4;i++)
    {
        if(this->_number.cell[i]!=other._number.cell[i])
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
    int sign1= (_number.cell[0] << 31) & 1;
    int sign2= (other._number.cell[0] << 31) & 1;

    if(sign1 == 0)
    { 
        if(sign2 == 1)
        {   
            return false;
        }
        for(int i =0 ; i < 4; i ++)
        {
            if(_number.cell[i] < other._number.cell[i])
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

        fourInts temp=_number;
        fourInts temp2=other._number;
        temp.cell[3] -= 1;
        if(temp.cell[3] == ~0)
        {
            temp.cell[2] -= 1;
            if(temp.cell[2] == ~0)
            {
                temp.cell[1] -= 1;
                if(temp.cell[1] == ~0)
                    temp.cell[0] -= 1;
            }
        }
        temp.cell[0] = ~ temp.cell[0];
        temp.cell[1] = ~ temp.cell[1];
        temp.cell[2] = ~ temp.cell[2];
        temp.cell[3] = ~ temp.cell[3];

        temp2.cell[3]-=1;
        if(temp2.cell[3]== ~0)
        {
            temp2.cell[2]-=1;
            if(temp2.cell[2]== ~0)
            {
                temp2.cell[1]-=1;
                if(temp2.cell[1]== ~0)
                    temp2.cell[0]-=1;
            }

        }        

        temp2.cell[0] = ~ temp2.cell[0];
        temp2.cell[1] = ~ temp2.cell[1];
        temp2.cell[2] = ~ temp2.cell[2];
        temp2.cell[3] = ~ temp2.cell[3];


        for(int i =0 ; i < 4; i ++)
        {
            if(temp.cell[i] < temp2.cell[i])
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

