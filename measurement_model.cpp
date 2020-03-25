#include "particle.cpp"
#include "feature.cpp"
#include "map.cpp"
#include "robot.cpp"
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
