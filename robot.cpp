#pragma once

class robot {
private:
 	float x;
	float y; 
	float theata;
	float pitch;
	float yaw;
	float roll;

public:
	robot(float, float, float, float, float,float );
	;

	float getX();
	float getY();
	float getT();

	void setX(float);
	void setY(float);
	void setT(float);


	float getP();
	float getYaw();
	float getR();

	void setP(float);
	void setYaw(float);
	void setR(float);

};

//Member Functions - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
robot::robot(float x, float y, float theata, float p, float yaw, float r){
	this -> x = x;
	this -> y = y;
	this -> theata = theata;
	this -> pitch = p;
	this -> yaw = yaw;
	this -> roll = r;
}

float robot::getX(){
	return x;
}
float robot::getY(){
	return y;
}
float robot::getT(){
	return theata;
}
void robot::setX(float x){
	this->x = x;
}
void robot::setY(float y){
	this->y = y;
}
void robot::setT(float theata){
	this->theata = theata;

float robot::getR(){
	return pitch;
}
float robot::getP(){
	return yaw;
}
float robot::getYaw(){
	return roll;
}
}
