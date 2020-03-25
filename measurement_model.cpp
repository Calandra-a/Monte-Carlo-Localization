#include "particle.cpp"
#include "feature.cpp"
#include "map.cpp"
#include "robot.cpp"
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
int prob(int);
int prob2(int);
void measurement_model(particle& newP, feature f, robot r, particle prevP, map inMap){

	    int j = inMap.findFromCorrespondence(f.getCorrespondence());
		int trueRange = sqrt(
        ((inMap.getFeature(j).getRangeX() - prevP.getX())*(inMap.getFeature(j).getRangeX() - prevP.getX())) +
        ((inMap.getFeature(j).getRangeY() - prevP.getY())*(inMap.getFeature(j).getRangeY() - prevP.getY()))
        );
        int range = sqrt(
        ((inMap.getFeature(j).getRangeX() - r.getX())*(inMap.getFeature(j).getRangeX() - r.getX())) +
        ((inMap.getFeature(j).getRangeY() - r.getY())*(inMap.getFeature(j).getRangeY() - r.getY()))
        );
        //printf("trueR: %d R: %d\n", trueRange, range);
		int trueBearing;
		int a = inMap.getFeature(j).getRangeY() - prevP.getY();
		int b =inMap.getFeature(j).getRangeX() - prevP.getX();
		int c = inMap.getFeature(j).getRangeY() - r.getY();
		int d = inMap.getFeature(j).getRangeX() - r.getX();
		printf ("%d,   %d     %d     %d\n",a,b,c,d);
		trueBearing = atan2((abs(inMap.getFeature(j).getRangeY() - prevP.getY())), abs((inMap.getFeature(j).getRangeX() - prevP.getX())));
		int bearing = atan2(abs((inMap.getFeature(j).getRangeY() - r.getY())), abs((inMap.getFeature(j).getRangeX() - r.getX())));
		// printf ("%d,   %d     %d\n",inMap.getFeature(j).getRangeY() , prevP.getY(), r.getY());
		// printf ("%d,   %d     %d\n",inMap.getFeature(j).getRangeX() , prevP.getX(), r.getX());

		printf("TB: %d B: %d \n", trueBearing, bearing);
		int q;
		int deltaR, deltaB, deltaC;
		deltaR = range - trueRange;
		//printf("range: %d trueRange: %d\n", range, trueRange);
		deltaB = bearing - trueBearing;
		deltaC = f.getCorrespondence() - inMap.getFeature(j).getCorrespondence();
		int error = rand() % 30;
		//printf("dR: %d dB: %d dC: %d \n", deltaR, deltaB, deltaC);
		//q = (prob(deltaR) + prob(deltaB) + prob(deltaC))/3;
		//q -= error;
		//printf("---d/3: %d\n",(deltaB+deltaR+deltaC));
		q = (prob2((abs(deltaB)+abs(deltaR)+abs(deltaC))));
        //printf("weights: %d\n",q);
        newP.setW(q);
}
int prob2(int delta){
	if (abs(delta) >= 60){
		return 1;
	}
	else 
		return 100 - abs(delta);
}
int prob(int delta) {
	int prob;
	prob = 100 - (delta / 100); //100% - delta(percentage)
	return prob;
}
>>>>>>> added in map feature and mm
