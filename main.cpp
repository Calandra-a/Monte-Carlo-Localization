#include "mcl.cpp"
#include "particle.cpp"
#include <iostream> 
#include "motion_model.cpp"
#include "plots/world.cpp"
#include "robot.cpp"
#include "particleFunctions.cpp"

int main(){
	pVector startP = genParticles(1000);
	robot r(30,30,60);
	plot(startP,r);
	for (int i =0; i <10; i++){
	int c[3] = {1,1,1};
	startP = mcl(startP,c,r);
	}

}