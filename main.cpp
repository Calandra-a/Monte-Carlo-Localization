#include "mcl.cpp"
#include "particle.cpp"
#include "motion_model.cpp"
#include "plots/world.cpp"
#include "robot.cpp"
#include "particleFunctions.cpp"
//Used for realtime runtime analysis
//#include <chrono>
//#include <stdio.h>
int main(){
	//Used for realtime runtime analysis
	//auto t1 = std::chrono::high_resolution_clock::now();
	pVector<particle> startP = genParticles(1500);
	robot r(50,50,50);
	map currMap;
	feature measurement;
	int range[2] = {90,90};
	measurement.setRange(range);
	//add feature to map if it is a newly measured feature
	if(currMap.checkMeasurement(measurement) == false){
		currMap.setFeature(measurement);
	}
	plot(startP,r);
	for (int i =0; i <10; i++){
		
		int c[2] = {5,5};
		startP = mcl(startP,c,measurement,r,currMap);
		plot(startP,r);
	}
	//Used for realtime runtime analysis
    //auto t2 = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
	//printf("Time: %d\n", duration);
    return 0;
}