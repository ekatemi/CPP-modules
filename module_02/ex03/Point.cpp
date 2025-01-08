#include "Point.hpp"

/*** Constructors */
Point::Point() : x(0), y(0){}

Point::Point(const float num1, const float num2) : x(num1), y(num2){}

Point::Point(const Point& other) : x(other.x), y(other.y){}

/** Overload assignment */
Point& Point::operator=(const Point &other){
    std::cout << "overload assignment do nothing\n";
    if (this != &other)
        {};
    return *this;
}

 /**Destructor */
Point::~Point(){}

/** Setter & getter */

Fixed Point::getPointX() const{
    return x;
}
Fixed Point::getPointY() const{
    return y;
}

/**Operator << overload */
std::ostream& operator<<(std::ostream& os, const Point& obj) {
    os << obj.getPointX() << " | " << obj.getPointY();
    return os;
}


