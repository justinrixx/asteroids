/****************************************************************************
 * rocks.cpp contains all of the member functions for LargeRock, MedRock and
 * SmallRock. They are so similar that it makes sense to put them in the same
 * place.
 * Authors: Justin Ricks and Devyn Stott
 ***************************************************************************/

#include "point.h"
#include "rock.h"
#include "uiDraw.h"

/***********************************************************
 * point function creates a point from the point class its useful
 * for not having to duplicate code in the following functions.
 ***********************************************************/
Point tempPoint(float x, float y)
{
   Point temp;
   temp.setX(x);
   temp.setY(y);
   return temp;
}

/*********************************************
 * MedRock default constructor
 *********************************************/
MedRock::MedRock()
{
   rotation = random(0, 360); // Random orientation
   size = 18;
   numSides = 7;
}

/*********************************************
 * LargeRock default constructor
 *********************************************/
LargeRock::LargeRock()
{
   v.setX(POINT_MAX);
   v.setY(random(-POINT_MAX, POINT_MAX));
   v.setDx(random(-20, 20) / 10.0);
   v.setDy(random(-20, 20) / 10.0);
   rotation = random(0, 360); // Random orientation
   size = 25;
   numSides = 5;
}

/*********************************************
 * SmallRock default constructor
 *********************************************/
SmallRock::SmallRock()
{
   rotation = random(0, 360);
   size = 10;
   numSides = 10;
}

/*********************************************
 * ROCK::DRAW
 *  draw function for all of the rocks
 *  This function handles pixel-perfect screen
 *    wrapping for rocks
 ********************************************/
void Rock :: draw()
{
   // We need to draw 5!! For screen wrapping
   // One where it is
   drawAsteroid(tempPoint(v.getX(), v.getY()), size, numSides, rotation);

   // One to the right
   drawAsteroid(tempPoint(v.getX() + 2*POINT_MAX, v.getY()), size, numSides, rotation);

   // One to the left
   drawAsteroid(tempPoint(v.getX() - 2*POINT_MAX, v.getY()), size, numSides, rotation);

   // One above it
   drawAsteroid(tempPoint(v.getX(), v.getY() + 2*POINT_MAX), size, numSides, rotation);

   // One below it
   drawAsteroid(tempPoint(v.getX(), v.getY() - 2*POINT_MAX), size, numSides, rotation);
}

/***************************************************
 * LARGEROCK::HIT
 *   Handles everything needed to be handled for hit detection
 *   and what is done upon a hit. Including adding new
 *   asteroids.
 ***************************************************/
void LargeRock :: hit(Projectile * rhs, Asteroids * pGame)
{
   if (this->isDead() || rhs->isDead())
      return;
   
   //This is only called when min distance is confirmed
   float minD = 0;
   minD = minDistance(this->v, rhs->getVector());

   if (minD <= size)
   {
      kill();
      rhs->kill();

      pGame->addScore(100);

      //spawn 2 med rocks and 1 small rock.
      MedRock * p1 = new MedRock;
      //set new velocities
      p1->getVector().setDy(this->v.getDy() + 1.0);
      p1->getVector().setDx(this->v.getDx());
      //set new starting point
      p1->getVector().setX(v.getX());
      p1->getVector().setY(v.getY());
      
      MedRock * p2 = new MedRock;
      p2->getVector().setDy(this->v.getDy() + -1.0);
      p2->getVector().setDx(v.getDx());
      p2->getVector().setX(v.getX());
      p2->getVector().setY(v.getY());
      
      SmallRock * p3 = new SmallRock;
      p3->getVector().setDx(this->v.getDx() + 2.0);
      p3->getVector().setDy(v.getDy());
      p3->getVector().setX(v.getX());
      p3->getVector().setY(v.getY());
      
      pGame->addItem(p1);
      pGame->addItem(p2);
      pGame->addItem(p3);
   }
}

/***************************************************
 * MEDROCK::HIT
 *   Handles everything needed to be handled for hit detection
 *   including what happens when a rock is hit.
 ***************************************************/
void MedRock :: hit(Projectile * rhs, Asteroids * pGame)
{
   if (this->isDead() || rhs->isDead())
      return;
   
   float minD = 0;
   minD = minDistance(this->v, rhs->getVector());
   if (minD <= size)
   {
      kill();
      rhs->kill();

      pGame->addScore(75);

      //spawn 2 new small rocks
      SmallRock * p1 = new SmallRock;
      p1->getVector().setDx(this->v.getDx() + 3.0);
      p1->getVector().setDy(v.getDy());
      p1->getVector().setX(v.getX());
      p1->getVector().setY(v.getY());

      SmallRock * p2 = new SmallRock;
      p2->getVector().setDx(this->v.getDx() - 3.0);
      p1->getVector().setDy(v.getDy());
      p2->getVector().setX(v.getX());
      p2->getVector().setY(v.getY());

      pGame->addItem(p1);
      pGame->addItem(p2);
   }
}
   
/***************************************************
 * SMALLROCK::HIT
 *   Handles everything needed to be handled for hit detection
 *   including the spawning of new asteroids.
 ***************************************************/
void SmallRock :: hit(Projectile * rhs, Asteroids * pGame)
{
   if (this->isDead() || rhs->isDead())
      return;
   
   float minD = 0;
   minD = minDistance(this->v, rhs->getVector());
   if (minD <= size)
   {
      kill();
      rhs->kill();

      static int smallRockDeaths;
      smallRockDeaths++;

      //spawn a new large on upon death
      if (smallRockDeaths % 4 == 0)
      {
         LargeRock * p1 = new LargeRock;

         pGame->addItem(p1);
      }
      
      pGame->addScore(50);
   }
}
