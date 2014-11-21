/**********************************************************
 * bullet.cpp project4 Asteroids
 * Authors: Justin Ricks and Devyn Stott
 ***********************************************************/

#include "vector.h"
#include "bullet.h"
#include "uiDraw.h"

#include <iostream>

using namespace std;

/*****************************************
 * Default constructor
 *****************************************/
Bullet :: Bullet() : Projectile()
{
   dead = false;
   life = 60;
}

/****************************************
 * BULLET::DRAW
 ***************************************/
void Bullet :: draw()
{
   Point point(v.getX(), v.getY());
   drawDot(point);
}

/****************************************
 * BULLET::ADVAVCE
 ***************************************/
void Bullet :: operator ++ (int postfix)
{
   v++;

   if (life <= 0)
      dead = true;
   else
      life--;
}
