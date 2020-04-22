#include "particle.cpp"
#include "feature.cpp"
#include "map.cpp"
#include "robot.cpp"
#include <math.h>
void measurement_model(particle&,feature,robot, particle, map);
int prob(int);
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
		int trueBearing;
		trueBearing = atan2((abs(inMap.getFeature(j).getRangeY() - prevP.getY())), abs((inMap.getFeature(j).getRangeX() - prevP.getX())));
		int bearing; 
		bearing= atan2(abs((inMap.getFeature(j).getRangeY() - r.getY())), abs((inMap.getFeature(j).getRangeX() - r.getX())));
		int q;
		int deltaR, deltaB;
		deltaR = range - trueRange;
		deltaB = bearing - trueBearing;
		int error = rand() % 30;

		q = (prob((abs(deltaB)+abs(deltaR))));
        newP.setW(q);
}
int prob(int delta){
	if (abs(delta) >= 60){
		return 1;
	}
	else 
		return 100 - abs(delta);
}

