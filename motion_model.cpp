#include "particle.cpp" 
#include <cmath.h>
void montion_model(particle, control, particle);

void montion_model(particle newP, control u, particle prevP){
	 //calculations
	newP.setX(prevP.getX() - (u.getV/u.getOmega));

}