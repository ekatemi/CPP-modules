#include "Point.hpp"


Fixed area(Point const a, Point const b, Point const c) {
    // Perform arithmetic operations with Fixed type
    Fixed sup =  (a.getPointX() * b.getPointY() - b.getPointX() * a.getPointY()) +
                 (b.getPointX() * c.getPointY() - c.getPointX() * b.getPointY()) +
                 (c.getPointX() * a.getPointY() - a.getPointX() * c.getPointY());

    if (sup < 0) {
        sup = sup * -1;
    }
    return sup;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed areaTr = area(a, b, c);
    Fixed areaTr1 = area(a, b, point);
    Fixed areaTr2 = area(b, c, point);
    Fixed areaTr3 = area(c, a, point);
    if (areaTr1 == 0 || areaTr2 == 0 || areaTr3 == 0)
        return false;
    return areaTr == (areaTr1 + areaTr2 + areaTr3);
}
