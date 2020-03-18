#include "/home/arc/Documents/MCL/matplotlib-cpp/matplotlibcpp.h"
#include <vector>
#include <math.h>
#include <stdio.h>
namespace plt = matplotlibcpp;
int plot(std::vector<particle> particles) {
    //plt::figure_size(10, 10);
    //landmark 1
    std::vector<double> x= {1,25,25,1,1};
    std::vector<double> y= {1,1,25,25,1};
    plt::plot(x,y,"r--");
    //landmark 2
    std::vector<double> x2= {90,120,120,90,90};
    std::vector<double> y2= {90,90,120,120,90};

    plt::plot(x2,y2,"r--");

    //robot
    std::vector<double> robotX= {30,40,40,30,30};
    std::vector<double> robotY= {30,30,40,40,30};

    plt::plot(robotX,robotY, "g-");

    //Particles 
    //px: x position of particle
    //py: y position of particle
    //dx: x position of where particle points
    //dy: y position of where particle points    
    std::vector<double> px;
    std::vector<double> py;
    std::vector<double> dx;
    std::vector<double> dy;
    double pi = 3.14159;
    
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