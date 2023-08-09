#include "Point.hpp"
#include <cmath>
#include <iostream>

Fixed area(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3)
{
   return ((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2)).abs() / Fixed(2.0f));
}

bool isInside(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3, Fixed x, Fixed y)
{  
   Fixed A = area (x1, y1, x2, y2, x3, y3);
   Fixed A1 = area (x, y, x2, y2, x3, y3); 
   Fixed A2 = area (x1, y1, x, y, x3, y3);
   Fixed A3 = area (x1, y1, x2, y2, x, y);
   return (A == A1 + A2 + A3);
}

//bissetrizes ponderadas
bool bsp( Point const a, Point const b, Point const c, Point const point){
   /* Area ABC */ 
   Fixed A = area (a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());

   /* Area PBC */ 
   Fixed A1 = area (point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY());
  
   /* Area PAC */ 
   Fixed A2 = area (a.getX(), a.getX(), point.getX(), point.getY(), c.getX(), c.getY());
  
   /* Area PAB */  
   Fixed A3 = area (a.getX(), a.getX(), b.getX(), b.getY(), point.getX(), point.getY());
   return (A == (A1 + A2 + A3));
}