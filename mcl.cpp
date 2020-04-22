#include "particle.cpp"
#include "motion_model.cpp"
#include "measurement_model.cpp"
#include "pVector.cpp"
#include <iostream>

pVector<particle> mcl (pVector<particle> prevParticles, int control[2], feature f, robot&  r, map currMap){
	
	pVector<particle> predictedParticleSet; 
	particle p(0,0,0,0); 
	for (int i =0; i < prevParticles.size(); i++){
		//sets x,y,theata
		motion_model(p, control, prevParticles.at(i));
		//sets weight value
		measurement_model(p,f,r,prevParticles.at(i),currMap);
		//adds particle to predicted set
		predictedParticleSet.push_back(p);
	}

	//Resample
	int total=0; 
	for (int i =0; i < predictedParticleSet.size(); i++){
		total = total + predictedParticleSet.at(i).getW();
	}
	pVector<particle> resample;
	srand(time(0));
	//Draw
	for (int i =0; i <predictedParticleSet.size() ; i++){
		int choose = rand()%total;
		int counter =0;
	  	for (int j=0; j < predictedParticleSet.size(); j++){
			  counter = counter + predictedParticleSet.at(j).getW();
			  if(counter > choose){
				  resample.push_back(predictedParticleSet.at(j));
				  break;
			  }
		  }
	}//end for
	return resample;
	
}