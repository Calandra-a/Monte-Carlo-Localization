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
        //printf("trueR: %d R: %d\n", trueRange, range);
		int trueBearing;
		
		trueBearing = atan2((inMap.getFeature(j).getRangeY() - prevP.getY()), (inMap.getFeature(j).getRangeX() - prevP.getX()));
		
		int bearing = atan2((inMap.getFeature(j).getRangeY() - r.getY()), (inMap.getFeature(j).getRangeX() - r.getX()));

		int q; //numerical probablity p(f[i] at time t | c[i] at time t, m, x at time t)
		int deltaR, deltaB, deltaC;
		deltaR = range - trueRange;
		deltaB = bearing - trueBearing;
		deltaC = f.getCorrespondence() - inMap.getFeature(j).getCorrespondence();
		int error = rand() % 30;

		q = (prob(deltaR) + prob(deltaB) + prob(deltaC))/3;
		q -= error;
        //printf("weights: %d\n",q);
        newP.setW(q);
}
int prob(int delta) {
	int prob;
	prob = 100 - (delta / 100); //100% - delta(percentage)
	return prob;
}