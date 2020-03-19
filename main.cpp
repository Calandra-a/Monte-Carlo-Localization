#include "mcl.cpp"
#include "particle.cpp"
#include <iostream> 
#include "motion_model.cpp"
#include "feature.cpp"
#include "map.cpp"
#include "plots/world.cpp"
#include "robot.cpp"
//prevParticle, control, measurment, setSize
int main(){
	std::vector<particle> startP = genParticles(300);
	//printParticles(startP);
	robot r(30,30,60);
	plot(startP,r);
	map currMap;
	feature measurement;
	int range[2] = {90,90};
	measurement.setRange(range);
	//add feature to map if it is a newly measured feature
	if(currMap.checkMeasurement(measurement) == false){
		currMap.setFeature(measurement);
	}
	for (int i =0; i <10; i++){
	int c[3] = {10,10,10};
	startP = mcl(startP,c,measurement,r, currMap);
	}

}