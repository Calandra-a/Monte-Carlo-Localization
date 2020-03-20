#include "mcl.cpp"
#include "particle.cpp"
#include <iostream> 
#include "motion_model.cpp"
#include "plots/world.cpp"
#include "robot.cpp"
//prevParticle, control, measurment, setSize
int main(){
	std::vector<particle> startP = genParticles(1000);
	//printParticles(startP);
	robot r(30,30,60);
	plot(startP,r);
	for (int i =0; i <50; i++){
	int c[3] = {1,1,1};
	startP = mcl(startP,c,r);
	}

}