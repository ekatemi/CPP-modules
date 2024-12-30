#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int fixed_point_nbr;
        static const int fract_bits; //all instances of class share that variable, val can not be changed
    public:
    //constructors
        //default constructor
        Fixed();
        //copy constructor
        Fixed(const Fixed& other);
    //copy assignment operator overload
        Fixed &operator=(const Fixed &other);
    //destructor
        ~Fixed();
    //methods
        //getter
        int getRawBits( void ) const;
        //setter
        void setRawBits( int const raw );
};

#endif
