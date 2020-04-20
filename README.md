# Monte-Carlo-Localization 
MCL implementation for CSI-5610 project

built with cmake version 3.5.1 and C++ 11
on Ubuntu 16.04

Setup Instructions

sudo apt-get install g++

sudo apt-get install python2.7

### downloaded cmake from

### https://cmake.org/files/v3.5/cmake-3.5.1.tar.gz

### extract cmake
 
### in cmake3.5.1 root

./bootstrap #note: make sure bootstrap has executable permission 

make

sudo make install

### cd out of cmake3.5.1

### for matplotlib-cpp install the following:

sudo apt-get install python-matplotlib python-numpy python2.7-dev

### Running the program:

### from root of Monte-Carlo-Localization folder:

cmake .

make

./mcl


#Gazebo

###Commands

####After make command

export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:~/Monte-Carlo-Localization/build

####include plugins folder in bashrc

export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/usr/lib/x86_64-linux-gnu/gazebo-7/plugins




- - - - - - - - - - - - - - - - - - - - - - -
When executed a plot will appear for each iteration of the algorithm (set for 10 iterations)
after each plot opens close it and the next iteration will open.


The matplolib-cpp folder is a clone of this third party repository
https://github.com/lava/matplotlib-cpp

utilized only for plotting functions for visualization of the project
