#include "mcl.cpp"
#include "particle.cpp"
#include "motion_model.cpp"
#include "plots/world.cpp"
#include "robot.cpp"
#include "particleFunctions.cpp"
//Used for realtime runtime analysis
//#include <chrono>
//#include <stdio.h>
int main(){
	//Used for realtime runtime analysis
	//auto t1 = std::chrono::high_resolution_clock::now();
<<<<<<< df69327c9a81a5d103aff1b8339e6892addfd34e
	pVector startP = genParticles(1000);
	robot r(100,100,100);
	plot(startP,r);
	for (int i =0; i <5; i++){
		
		int c[3] = {1,1,1};
		startP = mcl(startP,c,r);
=======
	pVector startP = genParticles(500);
	robot r(30,30,60);
	plot(startP,r);
	for (int i =0; i <20; i++){
	int c[3] = {1,1,1};
	startP = mcl(startP,c,r);
>>>>>>> removed some function calls and cleaned up code
	}
	//Used for realtime runtime analysis
    //auto t2 = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
	//printf("Time: %d\n", duration);
    return 0;
}