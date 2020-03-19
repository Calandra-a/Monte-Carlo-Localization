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
	std::vector<particle> startP = genParticles(20);
	printParticles(startP);
	robot r(30,30,60);
	plot(startP,r);
	int c[3] = {20,20,100};
	map currMap;
	feature measurement;
	//add feature to map if it is a newly measured feature
	if(currMap.checkMeasurement(measurement) == false){
		currMap.setFeature(measurement);
	}
	mcl(startP,c,measurement,r, currMap);
		
}