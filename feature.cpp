#pragma once
class feature{
    private:
        int range[2]; //[0] = x coordinate [1] = y coordinate
        int bearing;
        int Correspondence;
    public:
        int getRangeX();
        int getRangeY();
        int getBearing();
        int getCorrespondence ();
        void setRange(int[2]);
        void setBearing(int);
        void setCorrespondence (int);
};

int feature::getRangeX(){
    return range[0];
}
int feature::getRangeY(){
    return range[1];
}
int feature::getBearing(){
    return bearing;
}
int feature::getCorrespondence (){
    return Correspondence ;
}
void feature::setRange(int range[2]){
    this->range[0] = range[0];
    this->range[1] = range[1];
}
void feature::setBearing(int bearing){
    this->bearing = bearing;
}
void feature::setCorrespondence (int Correspondence ){
    this->Correspondence  = Correspondence ;
}