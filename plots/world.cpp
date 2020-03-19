#include "/home/arc/Documents/MCL/matplotlib-cpp/matplotlibcpp.h"
#include <vector>
#include <math.h>
#include <stdio.h>
#include "../robot.cpp"
#pragma once
namespace plt = matplotlibcpp;
int plot(std::vector<particle> particles, robot r) {
    double pi = 3.14159;

    //landmark 
    std::vector<int> x2= {90,91};
    std::vector<int> y2= {90,91};
    //std::vector<int> x2= {90,120,120,90,90};
    //std::vector<int> y2= {90,90,120,120,90};

    plt::plot(x2,y2,"r--");

    //robot
    
    std::vector<int> robotX;
    std::vector<int> robotY;
    std::vector<double> robotdX;
    std::vector<double> robotdY;
    robotX.push_back(r.getX());
    robotY.push_back(r.getY());
    robotdX.push_back(cos(r.getT()/(180/pi)));
    robotdY.push_back(sin(r.getT()/(180/pi)));
    printf("HEREEEEE %d %d  ----- %f",r.getX(),r.getY(), cos(r.getT()/(180/pi)));
    printf(" HEREEEE2 %d %d  ----- %f\n",r.getX(),r.getY(),sin(r.getT()/(180/pi)));
    plt::quiver(robotX,robotY,robotdX,robotdY);
    
    robotX.push_back(r.getX()+1);
    robotX.push_back(r.getX()+2);
    robotY.push_back(r.getY()+1);
    robotY.push_back(r.getY()+2);
    plt::plot(robotX,robotY, "g-");

    //Particles 
    //px: x position of particle
    //py: y position of particle
    //dx: x position of where particle points
    //dy: y position of where particle points
    std::vector<int> px;
    std::vector<int> py;
    std::vector<double> dx;
    std::vector<double> dy;
    
    
    for (int i = 0; i < particles.size(); i++){
        px.push_back(particles.at(i).getX());
        py.push_back(particles.at(i).getY());

        dx.push_back(/*particles.at(i).getX() +*/ cos(particles.at(i).getT()/(180/pi)));
        printf("cos %f", cos(particles.at(i).getT()/(180/pi)));

        dy.push_back(/*particles.at(i).getY() + */sin(particles.at(i).getT()/(180/pi)));
        printf(" sin %f\n",sin(particles.at(i).getT()/(180/pi)));
    }

    plt::quiver(px,py,dx,dy);
    
    plt::show();
}
