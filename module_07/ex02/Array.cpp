#include "Array.hpp"

Array::Array() { new T el[]; };
Array::Array(unsigned int n) {
    new T el[n]
};
Array::Array(const Array::Array &src) {};
Array::Array &operator=(const Array &src) {};
Array::~Array() {};
int size() const
{

    return el.length();
};
