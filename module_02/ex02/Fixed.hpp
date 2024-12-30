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
    
    //overloaded operators
        Fixed& operator=(const Fixed& other);
        //one arg because it is member function and we can use this
        Fixed operator+(const Fixed& b) const;
        Fixed operator-(const Fixed& b) const;
        Fixed operator*(const Fixed& b) const;
        Fixed operator/(const Fixed& b) const;

        bool operator==(const Fixed& b) const;
        bool operator!=(const Fixed& b) const;
        bool operator>(const Fixed& b) const;
        bool operator>=(const Fixed& b) const;
        bool operator<(const Fixed& b) const;
        bool operator<=(const Fixed& b) const;
        //postfix 
        //incr
        Fixed operator++(int);
        //decr
        Fixed operator--(int);
        //prefix 
        //incr
        Fixed& operator++();
        //decr
        Fixed& operator--();
    
    //member functions
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;
//          A static member function min that takes as parameters two references on fixed-point
// numbers, and returns a reference to the smallest one.
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);

        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        

};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
