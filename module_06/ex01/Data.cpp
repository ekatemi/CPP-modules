#include "Data.hpp"

Data::Data() : val(0) {};
Data::Data(const int i) : val(i) {};
Data::Data(const Data &src) : val(src.val) {};
Data &Data::operator=(const Data &src)
{
    if (this != &src)
    {
        val = src.val;
    }
    return *this;
}

Data::~Data() {};
void Data::setVal(int i) { val = i; }
int Data::getVal() const { return (val); };
