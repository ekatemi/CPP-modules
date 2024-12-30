#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int fixed_point_nbr;
        static const int fract_bits; //all instances of class share that variable, val can not be changed
    
    public:
    //Constructors
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        //copy constructor
        Fixed(const Fixed& other);

    //destructor
        ~Fixed();
    
    //overloaded copy assignment operator
        Fixed& operator=(const Fixed& other);
    
    
    //member functions
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
