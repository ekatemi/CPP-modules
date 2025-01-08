#include "Point.hpp"
bool bsp( Point const a, Point const b, Point const c, Point const point);




int main() {
    // Test case 1: Point inside the triangle
    Point a(0, -3);
    Point b(1, 7);
    Point c(-6, 9);
    Point pointInside(0, 1);

    std::cout << "Test case 1 (Point inside the triangle): "
              << bsp(a, b, c, pointInside) << std::endl;

    // Test case 2: Point on the edge of the triangle
    Point pointOnEdge(2.5, 0);  // On the edge between a and b
    std::cout << "Test case 2 (Point on the edge): "
              << bsp(a, b, c, pointOnEdge) << std::endl;

    // Test case 3: Point is one of the vertices of the triangle
    Point pointOnVertex(0, -3);  // Vertex a
    std::cout << "Test case 3 (Point on the vertex): "
              << bsp(a, b, c, pointOnVertex) << std::endl;

    // Test case 4: Point outside the triangle
    Point pointOutside(6, 6);
    std::cout << "Test case 4 (Point outside the triangle): "
              << bsp(a, b, c, pointOutside) << std::endl;

    return 0;
}
