#pragma once

class robot {
private:
 	int x;
	int y; 
	int theata;

public:

	void update(int,int,int);

	int getX();
	int getY();
	int getT();

	void setX(int);
	void setY(int);
	void setT(int);

};

//Member Functions - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void robot::update(int x, int y, int t){
	setX(x);
	setY(y);
	setT(t);
}

int robot::getX(){
	return x;
}
int robot::getY(){
	return y;
}
int robot::getT(){
	return theata;
}
void robot::setX(int x){
	this->x = x;
}
void robot::setY(int y){
	this->y = y;
}
void robot::setT(int theata){
	this->theata = theata;
}
