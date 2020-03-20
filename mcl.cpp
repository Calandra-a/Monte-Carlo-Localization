#include <vector>
#include "particle.cpp"
#include "motion_model.cpp"
#include "measurement_model.cpp"

//mcl input previous particle set, a control, a measurement, and a setsize
std::vector<particle> mcl (std::vector<particle> prevParticles, int control[2], robot&  r){
	
	 std::vector<particle> predictedParticleSet; 
	 particle p(0,0,0,0); 
	r.setX(r.getX()+control[0]);
	r.setY(r.getY()+control[1]);
	r.setT(r.getT()+control[2]);
	printf("X %d Y %d T %d", r.getX(), r.getY(), r.getT());
	for (int i =0; i < prevParticles.size(); i++){
		//sets x,y,theata
		motion_model(p, control, prevParticles.at(i));
		//sets weight value
		measurement_model(p,r ,prevParticles.at(i));
		//adds particle to predicted set
		//printf("newX %d, oldX %d:\n",p.getX(),prevParticles.at(i).getX());
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
		// printf("%d,",choose);
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

	// printf("RESAMPLE Weight------------------------------------------------------:");
	// for (int i =1300; i < resample.size(); i ++){
	// 	printf("%d, ",resample.at(i).getW());
	// }
	printf("\n");
	plot(resample,r);
	return resample;
	
}