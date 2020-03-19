#include "particle.cpp" 
#include "plots/world.cpp"
#include <math.h>

#pragma once
void motion_model(particle&, int[], particle);

void motion_model(particle& newP, int control[2], particle prevP){
	 //calculations
	 //control is a 3 item array, velocity (v), degrees of turn (omega), time the control lasts(delta t)
	newP.setX(
		prevP.getX() - 
		(control[0]/control[1])*sin(prevP.getT()) +
		(control[0]/control[1])*sin(prevP.getT() + control[1]*control[2])
	);
	newP.setY(
		prevP.getY() + 
		(control[0]/control[1])*cos(prevP.getT()) -
		(control[0]/control[1])*cos(prevP.getT() + control[1]*control[2])
	);
	newP.setT(
		prevP.getT() + (control[1]*control[2])
	);


}