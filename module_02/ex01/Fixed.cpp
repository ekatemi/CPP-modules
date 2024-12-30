#include "Fixed.hpp"

const int Fixed::fract_bits = 8;

//Constructors
Fixed::Fixed(): fixed_point_nbr(0) {
    std::cout << "Default constructor called" << std::endl;
}

//constructor assign int to fixed point nbr //move left on 8 or * 256
Fixed::Fixed(const int num) {
    fixed_point_nbr = num << fract_bits;
    std::cout << "int to fixed point constructor called" << std::endl;
}

//constructor assign float to fixed point nbr
Fixed::Fixed(const float num) {
    fixed_point_nbr = roundf(num * (1 << fract_bits));
    std::cout << "float to fixed point constructor called" << std::endl;
}

//copy constructor
Fixed::Fixed(const Fixed& other) : fixed_point_nbr(other.fixed_point_nbr) {
    std::cout << "Copy constructor called" << std::endl;
}

//copy assignment operator overload.
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;

        if (this != &other) { // Check for self-assignment
            fixed_point_nbr = other.getRawBits();
        }
        return *this; // Return current object to allow chained assignments
}

//destructor
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
} 

//Public methids
//getter/setter
int Fixed::getRawBits( void ) const {
    std::cout << "Get raw bits function called" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();  // toFloat() already does the conversion for us
    return os;
}
