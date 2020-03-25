#pragma once

class robot {
private:
 	int x;
	int y; 
	int theata;

public:
	robot(int, int, int );
	;

	int getX();
	int getY();
	int getT();

	void setX(int);
	void setY(int);
	void setT(int);

};

//Member Functions - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
robot::robot(int x, int y, int theata){
	this -> x = x;
	this -> y = y;
	this -> theata = theata;
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
