//#include "mcl.cpp"
#include "particle.cpp"
#include <iostream> 
#include "motion_model.cpp"
//prevParticle, control, measurment, setSize
int main(){
	std::vector<particle> startP = genParticles(20);
	printParticles(startP);
}