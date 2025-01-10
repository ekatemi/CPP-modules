#include "Fixed.hpp"

const int Fixed::fract_bits = 8;

//Constructors
Fixed::Fixed(): fixed_point_nbr(0) {
}

//constructor assign int to fixed point nbr //move left on 8 or * 256
Fixed::Fixed(const int num) {
    fixed_point_nbr = num << fract_bits;
}

//constructor assign float to fixed point nbr
Fixed::Fixed(const float num) {
    fixed_point_nbr = roundf(num * (1 << fract_bits));
    
}

//copy constructor
Fixed::Fixed(const Fixed& other) : fixed_point_nbr(other.fixed_point_nbr) {
   
}

//copy assignment operator overload.
Fixed& Fixed::operator=(const Fixed& other) {
        if (this != &other) { // Check for self-assignment
            fixed_point_nbr = other.getRawBits();
        }
        return *this; // Return current object to allow chained assignments
}

//destructor
Fixed::~Fixed(){
} 

//Public methids
//getter/setter
int Fixed::getRawBits( void ) const {
    return fixed_point_nbr;
}
void Fixed::setRawBits( int const raw )
{
    fixed_point_nbr = raw;
}

//converts fixed point to float
float Fixed::toFloat(void) const {
    return (float)fixed_point_nbr / (float)(1 << fract_bits); // divide on 2^8 or 256
}
//converts fixed point to int
int Fixed::toInt(void) const {
    return fixed_point_nbr >> fract_bits; 
}

//operator << overload
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}

Fixed Fixed::operator+(const Fixed& b) const {
    Fixed res;
    res.setRawBits(this->getRawBits() + b.getRawBits());
    return res;
}

Fixed Fixed::operator-(const Fixed& b) const {
    Fixed res;
    res.setRawBits(this->getRawBits() - b.getRawBits());
    return res;
}

Fixed Fixed::operator*(const Fixed& b) const {
    Fixed res;
    res.setRawBits((this->getRawBits() * b.getRawBits()) >> fract_bits);
    return res;
}

Fixed Fixed::operator/(const Fixed& b) const {
    Fixed res;
    res.setRawBits((this->getRawBits() << fract_bits) / b.getRawBits());
    return res;
}

bool Fixed::operator==(const Fixed& b) const {
    return this->getRawBits() == b.getRawBits();
}
bool Fixed::operator!=(const Fixed& b) const {
    return this->getRawBits() != b.getRawBits();
}
bool Fixed::operator>(const Fixed& b) const {
    return this->getRawBits() > b.getRawBits();
}
bool Fixed::operator>=(const Fixed& b) const {
    return this->getRawBits() >= b.getRawBits();
}
bool Fixed::operator<(const Fixed& b) const {
    return this->getRawBits() < b.getRawBits();
}
bool Fixed::operator<=(const Fixed& b) const {
    return this->getRawBits() <= b.getRawBits();
}
//postfix incr
Fixed Fixed::operator++(int) {
    Fixed temp = *this;  // Save the current value (this will be returned)
    this->setRawBits(this->getRawBits() + 1);  // Increment the raw value
    return temp;  // Return the original value before increment
}

//postfix decr
Fixed Fixed::operator--(int) {
    Fixed temp = *this;  // Save the current value (this will be returned)
    this->setRawBits(this->getRawBits() - 1);  
    return temp;  // Return the original value before increment
}
//prefix incr
Fixed& Fixed::operator++() {
    this->setRawBits(this->getRawBits() + 1); // Increment raw bits
    return *this; // Return the incremented object
} 

//prefix decr
Fixed& Fixed::operator--() {
    this->setRawBits(this->getRawBits() - 1); // Increment raw bits
    return *this; // Return the incremented object
} 

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}
