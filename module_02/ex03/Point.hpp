#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        const Fixed x;
        const Fixed y;
    public:
    /**Constructors */
        Point();
        Point(const float num1, const float num2);
        Point(const Point &other);
    /**Copy assignment overload */
        Point& operator=(const Point &other);
    /**Destructor */
        ~Point();

    /** Setter & getter */
    Fixed getPointX() const;
    Fixed getPointY() const;
};

std::ostream& operator<<(std::ostream& os, const Point& obj);

#endif
