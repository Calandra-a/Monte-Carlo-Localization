#pragma once
class particle {
private:
 	int x;
	int y; 
	int theata;
	int weight;
public:
	particle(int, int, int, int );
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

//Member Functions
particle::particle(int x, int y, int theata, int weight){
			this->x = x;
			this->y = y;
			this->theata = theata;
			this->weight = weight;
}

int particle::getX(){
	return x;
}
int particle::getY(){
	return y;
}
int particle::getT(){
	return theata;
}
int particle::getW(){
	return weight;
}
void particle::setX(int x){
	this->x = x;
}
void particle::setY(int y){
	this->y = y;
}
void particle::setT(int theata){
	this->theata = theata;
}
void particle::setW(int weight){
	this->weight = weight;
}

