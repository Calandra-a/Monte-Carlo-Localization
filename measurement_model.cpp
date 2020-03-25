#include "particle.cpp"
#include "robot.cpp"
<<<<<<< df69327c9a81a5d103aff1b8339e6892addfd34e
<<<<<<< c04f93f229655bc9cef1aea8318a619e038cc3c6
#include "helperFunctions.cpp"
#include "iostream"
void measurement_model(particle&,robot, particle);
int prob(int);
int prob2(int);
void measurement_model(particle& newP, robot r, particle prevP){
int deltaX = abs(r.getX() - prevP.getX());
int deltaY = abs(r.getY() - prevP.getY());
int deltaT = abs(r.getY() - prevP.getY());
int totalDelta = deltaT+deltaX+deltaY;
int weight=100;
if(totalDelta >=495){
	weight = 1;
}
else
{
	int modifer =0;
	for(int i =5; i< totalDelta; i+=5 ){
		weight -= 1+modifer;
		modifer = weight*.05;
		if(weight<0){
			weight =1;
			break;
		}
	}	
}
newP.setW(weight);
}
=======
#include <math.h>
void measurement_model(particle&,feature,robot, particle, map);
=======
#include "helperFunctions.cpp"
#include "iostream"
void measurement_model(particle&,robot, particle);
>>>>>>> removed some function calls and cleaned up code
int prob(int);
int prob2(int);
void measurement_model(particle& newP, robot r, particle prevP){
int deltaX = abs(r.getX() - prevP.getX());
int deltaY = abs(r.getY() - prevP.getY());
int deltaT = abs(r.getY() - prevP.getY());
int totalDelta = deltaT+deltaX+deltaY;
int weight=100;
if(totalDelta >=495){
	weight = 1;
}
else
{
	int modifer =0;
	for(int i =5; i< totalDelta; i+=5 ){
		weight -= 1+modifer;
		modifer = weight*.05;
		if(weight<0){
			weight =1;
			break;
		}
	}	
}
newP.setW(weight);
}
<<<<<<< df69327c9a81a5d103aff1b8339e6892addfd34e
int prob(int delta) {
	int prob;
	prob = 100 - (delta / 100); //100% - delta(percentage)
	return prob;
}
>>>>>>> added in map feature and mm
=======
>>>>>>> removed some function calls and cleaned up code
