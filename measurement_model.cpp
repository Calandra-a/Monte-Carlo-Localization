#include "particle.cpp"
#include "robot.cpp"
#include "helperFunctions.cpp"
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
