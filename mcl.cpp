
#include "particle.cpp"
//mcl input previous particle set, a control, a measurement, and a setsize
particle mcl (prevParticle, control, measurment, setSize){
	
	predictedParticleSet = Particles = null; 

	for (int i =0; i < setSize; i++){
		//sets x,y,theata
		Particles.at(i). = sample_motion_model(control, prevParticle(i));
		//sets weight value
		Particles.at(i) = measurement_model(measurment, particle(i), setSize);
		//adds particle to predicted set
		predictedParticleSet.add(particle(i),weight(i));
	}
	for (int i =0; i < setSize; i++){
		//resampling
	}
}