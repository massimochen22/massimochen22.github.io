#include "circle.h"
#include <iostream>

using namespace std;



    double radius;


    Circle::Circle(double rad){
        radius = rad;

    }

    void Circle::setRadius( double d){
        radius = d;

    }

    double Circle::getRadius()const{
        return radius;
    }

    double Circle::getDiameter()const{
        return radius*2;
    }

    double Circle::getCircumference()const{
        return radius*2* PI;
    }
    double Circle::getArea()const{

        return PI*radius*radius;

    }

    string Circle::getName()const{
        return "Circle";
    }

    // output Circle object data member
    void Circle::print()const{
        std::cout<<"Radius is "<<radius<<" Area is "<<PI*radius*radius<<" and circumference is "<<radius*2* PI<<endl;
    }


