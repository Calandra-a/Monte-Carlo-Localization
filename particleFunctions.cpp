#include "pVector.cpp"
#include "particle.cpp"
#include <stdlib.h>
#include <time.h>
//Functions - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
pVector<particle> genParticles(int);
void printParticles(pVector<particle>);//todo remove

pVector<particle> genParticles(int setSize){
	srand(time(0));
	pVector<particle> p;
	for(int i =0; i < setSize; i++){
		particle part(rand()%200,rand()%200,rand()%360,0);
		p.push_back(part);
	}
	return p;
}