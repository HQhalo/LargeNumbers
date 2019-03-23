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

bool QInt::operator< ( QInt const &other)
{
   
}
QInt::QInt()
{

}

QInt::~QInt()
{
    
}