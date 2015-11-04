#########################################################################
## Project 4 :: Asteroids
## Authors:
## 	Devyn Stott and Justin Ricks
## Summary:
## 	The simple atari game of asteroids, it is comprised of a ship that
## goes around and shoots rocks for points. It's simplicity is addictive
## Extra credit oppertunities include colorful ship and score, proper item
## wrapping, so the item shows up on both sides of the screen at the same
## time, and score.
##      You'll find the game of asteroids in a.out and driver programs
##  in the later parts of the makefile.   
#######################################################################

#################################
## The Real Deal
#################################
a.out: asteroidsDriver.cpp asteroids.h asteroids.o rock.o ship.o uiDraw.o uiInteract.o bullet.o vector.o score.o
	g++ -o a.out asteroidsDriver.cpp asteroids.o vector.o ship.o rock.o bullet.o uiDraw.o uiInteract.o score.o -lglut -lGL -lGLU -O3

#################################
## Driver Programs
#################################
bulletDriver: bullet.o asteroids.o uiDraw.o uiInteract.o bulletDriver.cpp vector.o asteroids.h
	g++ -o bulletDriver bulletDriver.cpp bullet.o vector.o asteroids.o uiDraw.o uiInteract.o -lglut -lGLU -lGL -O3

shipDriver: ship.o uiDraw.o uiInteract.o asteroids.o shipDriver.cpp asteroids.h vector.o
	g++ -o shipDriver shipDriver.cpp shootable.h ship.o asteroids.o uiDraw.o uiInteract.o vector.o -lglut -lGLU -lGL -O3

rockDriver: rock.o asteroids.h uiDraw.o uiInteract.o rockDriver.cpp vector.o asteroids.o
	g++ -o rockDriver rockDriver.cpp rock.o vector.o uiDraw.o uiInteract.o asteroids.o -lglut -lGLU -lGL -O3

asteroidsDriver: asteroidsDriver.cpp asteroids.h asteroids.o rock.o ship.o uiDraw.o uiInteract.o bullet.o vector.o score.o
	g++ -o asteroidsDriver asteroidsDriver.cpp asteroids.o vector.o ship.o rock.o bullet.o uiDraw.o uiInteract.o score.o -lglut -lGLU -lGL -O3

################################
## Dependencies (.o's)
################################
asteroids.o: asteroids.cpp asteroids.h
	g++ -c asteroids.cpp
rock.o: rock.cpp asteroids.h rock.h
	g++ -c rock.cpp
ship.o: ship.cpp ship.h asteroids.h shootable.h
	g++ -c ship.cpp
Bullet.o: bullet.cpp bullet.h projectile.h
	g++ -c bullet.cpp
vector.o: vector.cpp vector.h point.h
	g++ -c vector.cpp
socre.o: score.cpp score.h point.h
	g++ -c score.cpp
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp
uiInteract.o: uiInteract.cpp uiInteract.h point.h
	g++ -c uiInteract.cpp

## Additional Options ##
clean:
	rm *~ *.o *# a.out
tar:
	tar -cf asteroids.tar *.cpp *.h makefile

######################################
## Test for custom asteroid drawing ##
######################################
## This driver was created to test the custom drawAsteroid
##  function. It also draws a circle around it to show where
##  collisions will occur
######################################
drawTest: drawTest.cpp uiDraw.o uiInteract.o point.h
	g++ -o drawTest drawTest.cpp uiDraw.o uiInteract.o -lglut -lGLU -lGL
