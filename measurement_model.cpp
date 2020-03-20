#include "particle.cpp"
#include "robot.cpp"
#include <math.h>
void measurement_model(particle&,robot, particle);
int prob(int);
int prob2(int);
void measurement_model(particle& newP, robot r, particle prevP){
int deltaX = abs(r.getX() - prevP.getX());
printf("delta %d,robot  %d,prev %d \n--------", deltaX,r.getX(), prevP.getX());
int deltaY = abs(r.getY() - prevP.getY());
int deltaT = abs(r.getT() - prevP.getT());

int totalDelta = deltaT*1.5+deltaX+deltaY;
//printf("delta: %d\n",totalDelta);
int weight=100;
if(totalDelta >=495){
	weight = 1;
}
else
{
	for(int i =5; i< totalDelta; i+=5 ){
		weight -= 1;
	}
}

newP.setW(weight);
}
