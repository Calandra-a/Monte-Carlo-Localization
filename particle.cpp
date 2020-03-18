#include <stdio.h>
#include <vector>


class particle {
private:
 	int x;
	int y; 
	int theata;
	int weight;
public:
	particle(int x, int y, int theata, int weight);
	void printParticle();
	int getX();
	int getY();
	int getT();
	int getW();
	void setX(int);
	void setY(int);
	void setT(int);
	void setW(int);
};

//Member Functions - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
particle::particle(int x, int y, int theata, int weight){
			this->x = x;
			this->y = y;
			this->theata = theata;
			this->weight = weight;
}
void particle::printParticle(){
		printf("x: %d y: %d theata: %d weight: %d\n",x,y,theata,weight);
}

int getX(){
	return x;
}
int getY(){
	return y;
}
int getT(){
	return theata;
}
int getW(){
	return weight;
}
void setX(int x){
	this->x = x
}
void setY(int y){
	this->y = y
}
void setX(int theata){
	this->theata = theata
}
void setX(int weight){
	this->weight = weight
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