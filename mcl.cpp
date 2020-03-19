#include <vector>
#include "particle.cpp"
#include "motion_model.cpp"
#include "feature.cpp"
#include "map.cpp"
#include "measurement_model.cpp"

//mcl input previous particle set, a control, a measurement, and a setsize
std::vector<particle> mcl (std::vector<particle> prevParticles, int control[2], feature measured,robot&  r, map currMap){
	
	 std::vector<particle> predictedParticleSet; 
	 particle p(0,0,0,0); 
	r.setX(r.getX()+control[0]);
	r.setY(r.getY()+control[1]);
	r.setT(r.getT()+control[2]);
	for (int i =0; i < prevParticles.size(); i++){
		//sets x,y,theata
		motion_model(p, control, prevParticles.at(i));
		//sets weight value
		measurement_model(p, measured,r ,prevParticles.at(i), currMap);
		//adds particle to predicted set
		predictedParticleSet.push_back(p);
	}
	
	// printf("Weight:");
	// for (int i =0; i < predictedParticleSet.size(); i ++){
	// 	printf("%d, ",predictedParticleSet.at(i).getW());
	// }
	// printf("\n");

	//plot(predictedParticleSet,r);
	int total=0;
	for (int i =0; i < predictedParticleSet.size(); i++){
		total = total + predictedParticleSet.at(i).getW();
		//printf("Total %d: %d \n",i, total);
	}
	
	
	std::vector<particle> resample;
	srand(time(0));
	
	for (int i =0; i <predictedParticleSet.size() ; i++){
		int choose = rand()%total;
		//printf("choose %d\n", choose);
		int counter =0;
	  	for (int j=0; j < predictedParticleSet.size(); j++){
			  counter = counter + predictedParticleSet.at(j).getW();
			  if(counter > choose){
				  resample.push_back(predictedParticleSet.at(j));
				  //printf("Pushed: %d\n", j);
				  break;
				  //printf("here check\n");
			  }
		  }
	}//end for
	plot(resample,r);
	return resample;
	
}