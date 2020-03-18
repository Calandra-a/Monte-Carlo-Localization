#include <vector>
#include "particle.cpp"
#include "motion_model.cpp"
//mcl input previous particle set, a control, a measurement, and a setsize
particle mcl (std::vector<particle> prevParticles, int control[2], measurment, int setSize){
	
	 std::vector<particle> predictedParticleSet = null; 
	 particle p = null; 
	for (int i =0; i < setSize; i++){
		//sets x,y,theata
		motion_model(p, control, prevParticles.at(i));
		//sets weight value
		measurement_model(p, measurment, particle(i), setSize);
		//adds particle to predicted set
		predictedParticleSet.add(p);
	}
	for (int i =0; i < setSize; i++){
		//resampling
	}
}