#include "particle.cpp"
#include "feature.cpp"
#include "map.cpp"
#include <math.h>
void measurement_model(particle,feature, particle, map);
int prob(int);
void measurement_model(particle newP, feature f, particle prevP, map inMap){

	    int j = inMap.findFromCorrespondence(f.getCorrespondence());
		int trueRange = sqrt(
        ((inMap.getFeature(j).getRangeX() - prevP.getX())*(inMap.getFeature(j).getRangeX() - prevP.getX())) +
        ((inMap.getFeature(j).getRangeY() - prevP.getY())*(inMap.getFeature(j).getRangeY() - prevP.getY()))
        );
        int range = sqrt(
        ((inMap.getFeature(j).getRangeX() - newP.getX())*(inMap.getFeature(j).getRangeX() - newP.getX())) +
        ((inMap.getFeature(j).getRangeY() - newP.getY())*(inMap.getFeature(j).getRangeY() - newP.getY()))
        );
        printf("trueR: %d R: %d\n", trueRange, range);
		int trueBearing;
		
		trueBearing = atan2((inMap.getFeature(j).getRangeY() - prevP.getY()), (inMap.getFeature(j).getRangeX() - prevP.getX()));
		

		int q; //numerical probablity p(f[i] at time t | c[i] at time t, m, x at time t)
		int deltaR, deltaB, deltaC;
		deltaR = range - trueRange;
		deltaB = f.getBearing() - trueBearing;
		deltaC = f.getCorrespondence() - inMap.getFeature(j).getCorrespondence();
		int error = rand() % 30;

		q = (prob(deltaR) + prob(deltaB) + prob(deltaC))/3;
		q -= error;
        printf("q: %d\n",q);
        newP.setW(q);
}
int prob(int delta) {
	int prob;
	prob = 100 - (delta / 100); //100% - delta(percentage)
	return prob;
}