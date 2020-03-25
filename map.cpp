#include "feature.cpp"
#include "pVector.cpp"
#pragma once
class map{
    private:
        pVector m;
    public:
        feature getFeature(int); 
        void setFeature(feature);
        bool checkMeasurement(feature);
        int findFromCorrespondence(int);
};

feature map::getFeature(int i){
    return m.at(i);
}
void map::setFeature(feature f){
    m.push_back(f);
}
bool map::checkMeasurement(feature f){
    for(int i =0; i < m.size(); i++){
    if(f.getCorrespondence()  == m.at(i).getCorrespondence()){
        return true;
        }
    }
    return false;
}
int map::findFromCorrespondence(int c){
    for(int i =0; i < m.size(); i++){
        if(c == m.at(i).getCorrespondence() ){
        return i;
        }
    }
    return -1;
}