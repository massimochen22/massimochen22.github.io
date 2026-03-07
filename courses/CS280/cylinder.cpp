#include "cylinder.h" 
#include <iostream>

using namespace std;

double height;
const double PI = 3.14159;

Cylinder::Cylinder(double rad, double hei){
    radius = rad;
    height = hei;
}
void Cylinder::setHeight( double hei){
    height = hei;
}
double Cylinder::getHeight() const{
    return height;
}

double Cylinder::getArea() const{
    return (radius*2*PI*height)+(radius*radius*2*PI);
}
double Cylinder::getVolume()const{
    return radius*radius*PI*height;
}
        
// return name of shape (i.e., "Cylinder" )
string Cylinder::getName()const{
    return "Cylinder";
}

void Cylinder::print()const{
    std::cout<<"Radius is "<<radius<<" and height is "<<height<<" Area is "<<(radius*2*PI*height)+(radius*radius*2*PI)<<" and volume is "<< radius*radius*PI*height<<endl;
} 


