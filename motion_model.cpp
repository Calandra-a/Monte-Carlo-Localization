#include "particle.cpp" 
#include "plots/world.cpp"
#include <math.h>
#pragma once
void motion_model(particle&, int[], particle);
int sample_normal_distribution(int);

void motion_model(particle& newP, int control[2], particle prevP){
	int v = control[0];
	int w = control[1];
	int vPred = control[0] +sample_normal_distribution((v*v)+(w*w));
	int wPred = control[1] +sample_normal_distribution((v*v)+(w*w));
	int preturb = sample_normal_distribution((v*v)+(w*w));
	int xPred = prevP.getX() - ((vPred/wPred)*sin(prevP.getT())) + ((vPred/wPred)*sin(prevP.getT() + wPred));
	int yPred = prevP.getY() + ((vPred/wPred)*cos(prevP.getT())) - ((vPred/wPred)*cos(prevP.getT() + wPred));
	int tPred = prevP.getT() + wPred + preturb;
	newP.setX(xPred);
	newP.setY(xPred);
	newP.setT(tPred);
}

int sample_normal_distribution(int b){
	int sample = 0;
	srand(time(0));
	for (int i = 0; i < 12; i++){
		sample +=  (rand()%(b+b)-b);
	}
}