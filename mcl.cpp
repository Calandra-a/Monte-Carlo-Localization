
#include "particle.cpp"
//mcl input previous particle set, a control, a measurement, and a setsize
particle mcl (prevParticle, control, measurment, setSize){
	
	 std::vector<particle> predictedParticleSet = null; 
	 particle p = null; 
	for (int i =0; i < setSize; i++){
		//sets x,y,theata
		motion_model(p, control, prevParticle(i));
		//sets weight value
		measurement_model(p, measurment, particle(i), setSize);
		//adds particle to predicted set
		predictedParticleSet.add(p);
	}
	for (int i =0; i < setSize; i++){
		//resampling
	}
}