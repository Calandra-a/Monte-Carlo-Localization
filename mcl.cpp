#include <vector>
#include "particle.cpp"
#include "motion_model.cpp"
#include "feature.cpp"
#include "map.cpp"
#include "measurement_model.cpp"

//mcl input previous particle set, a control, a measurement, and a setsize
particle mcl (std::vector<particle> prevParticles, int control[2], feature measured,robot r, map currMap){
	
	 std::vector<particle> predictedParticleSet; 
	 particle p(0,0,0,0); 
	r.setX(r.getX()+control[0]);
	r.setY(r.getY()+control[1]);
	r.setT(r.getT()+control[2]);
	for (int i =0; i < prevParticles.size(); i++){
		//sets x,y,theata
		motion_model(p, control, prevParticles.at(i));
		//sets weight value
		measurement_model(p, measured, prevParticles.at(i), currMap);
		//adds particle to predicted set
		predictedParticleSet.push_back(p);
	}
	
	
	for (int i =0; i < predictedParticleSet.size(); i ++){
		printf("weight: %d\n",predictedParticleSet.at(i).getW());
	}

	plot(predictedParticleSet,r);
	//for (int i =0; i < setSize; i++){
		//resampling
	//}
}