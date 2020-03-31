#include "particle.cpp" 
#include "plots/world.cpp"
#include <math.h>
#include <stdlib.h>
#include <time.h>  
#pragma once
void motion_model(particle&, int[], particle);
int sample_normal_distribution(int);

void motion_model(particle& newP, int control[2], particle prevP){
	srand(time(0));
	int v = control[0];
	int w = control[1];
	int vPred = control[0] +sample_normal_distribution((v*v)+(w*w));
	int wPred = control[1] +sample_normal_distribution((v*v)+(w*w));
	int rotation = sample_normal_distribution((v*v)+(w*w));
	int xPred = prevP.getX() - ((vPred/wPred)*sin(prevP.getT())) + ((vPred/wPred)*sin(prevP.getT() + wPred));
	int yPred = prevP.getY() + ((vPred/wPred)*cos(prevP.getT())) - ((vPred/wPred)*cos(prevP.getT() + wPred));
	int tPred = prevP.getT() + wPred + rotation;
	newP.setX(xPred);
	newP.setY(xPred);
	newP.setT(tPred);
}

int sample_normal_distribution(int b){
	int sample = 0;
	for (int i = 0; i < 12; i++){
		sample +=  (rand()%(b+b)-b);
	}
	return sample;
}