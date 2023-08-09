#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
    Point a(0, 0);
    Point b(5, 0);
    Point c(2.5, 5);

    Point point(2.5, 0);
    std::cout << "x: "<< point.getX() <<  "   y:" << point.getY() << std::endl;
    std::cout << bsp(a, b, c, point) << std::endl;
    Point point2(2.5, 1000);
    std::cout << "x: "<< point2.getX() << "   y:" << point2.getY() << std::endl;
    std::cout << bsp(a, b, c, point2) << std::endl;
    Point point3(2.5, 4.5);
    std::cout << "x: "<< point3.getX() << "   y:" << point3.getY() << std::endl;
    std::cout << bsp(a, b, c, point3) << std::endl;
    Point point4(3, 5);
    std::cout << "x: "<< point4.getX() << "   y:" << point4.getY() << std::endl;
    std::cout << bsp(a, b, c, point4) << std::endl;
    return 0;
}