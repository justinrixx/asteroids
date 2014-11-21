#include "vector.h"
#include <iostream>
using namespace std;

//float Point::xMin = -10.0;
//float Point::xMax =  10.0;
//float Point::yMin = -10.0;
//float Point::yMax =  10.0;

/*********************************
 * Driver provided by bro helfrich and edited by us to test out vector class.
 *********************************/
int main()
{
   cout.setf(ios::fixed);
   cout.precision(1);
   
   // fill the first vector
   Vector v1;
   float x, y, dx, dy;
   cout << "First vector  (x y dx dy): ";
   cin  >> x >> y >> dx >> dy;
   v1.setX(x);
   v1.setY(y);
   v1.setDx(dx);
   v1.setDy(dy);
   
   while (true)
   {
      // fill the second vector
      Vector v2;
      cout << "Second vector (x y dx dy): ";
      cin  >> x >> y>> dx >> dy;
      v2.setX(x);
      v2.setY(y);
      v2.setDx(dx);
      v2.setDy(dy);
      
      
      // give up the goods
      cout << "\tMinimum Distance:   " << minDistance(v1,v2)       << endl;
      cout << "\tvector 2:           " << v2.getX() << " " << v2.getY() << " " << v2.getDx() << " " << v2.getDy() << " " << endl;
      //cout << "\tvector 2 angle:     " << v2.getAngle() << endl;
      //cout << "\tvector 2 magnitude: " << v2.getMag()   << endl;
      v2 += v1;
      cout << "\tv2 += v1:           " << v2.getX() << " " << v2.getY() << " " << v2.getDx() << " " << v2.getDy() << " " << endl;

   }

   return 0;
}
