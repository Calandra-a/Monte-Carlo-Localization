#include <stdio.h>
#include <vector>


class particle {
private:
 	int x;
	int y; 
	int theata;
	int weight;
public:
	particle(int x, int y, int theat, int weight);
	void getParticle();
};

//Member Functions - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
particle::particle(int x, int y, int theata, int weight){
			this->x = x;
			this->y = y;
			this->theata = theata;
			this->weight = weight;
}
void particle::getParticle(){
		printf("x: %d y: %d theata: %d weight: %d\n",x,y,theata,weight);
}

//Functions - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
std::vector<particle> genParticles(int);
void printParticles(std::vector<particle>);

std::vector<particle> genParticles(int setSize){
	std::vector<particle> p;
	for(int i =0; i < setSize; i++){
		particle part(1,2,3,4);
		p.push_back(part);
	}
	return p;
}

void printParticles(std::vector<particle> p){
	for(int i=0; i<p.size();i++){
		p.at(i).getParticle();
	}
}