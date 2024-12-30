#include "Fixed.hpp"

const int Fixed::fract_bits = 8;

//Constructors
Fixed::Fixed(): fixed_point_nbr(0) {
    std::cout << "Default constructor called" << std::endl;
}
//copy constructor
Fixed::Fixed(const Fixed &other) : fixed_point_nbr(other.fixed_point_nbr) {
    std::cout << "Copy constructor called" << std::endl;
}

//copy assignment operator overload.
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;

        if (this != &other) { // Check for self-assignment
            this->fixed_point_nbr = other.getRawBits();
        }
        return *this; // Return current object to allow chained assignments
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
} //destructor

int Fixed::getRawBits( void ) const {
    std::cout << "Get raw bits function called" << std::endl;
    return fixed_point_nbr;
}
void Fixed::setRawBits( int const raw )
{
    fixed_point_nbr = raw;
}
