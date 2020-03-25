#include "pVector.cpp"
#include "particle.cpp"
//Functions - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
pVector genParticles(int);
void printParticles(pVector);//todo remove

pVector genParticles(int setSize){
	srand(time(0));
	pVector p;
	for(int i =0; i < setSize; i++){
		particle part(rand()%200,rand()%200,rand()%360,0);
		p.push_back(part);
	}
	return p;
}
