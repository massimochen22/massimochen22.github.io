#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
    
#include "shapescollection.cpp"
using namespace std;
     
int main()
{
    Circle2 circle1( 3.5 );

    std::cout<<circle1.getArea();
    
}