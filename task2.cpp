#include <iostream>

class ParameterFigure{
public:
    double coordinatesCenter[2];
    enum colors{
        red,
        blue,
        green,
        yellow,
        null,
    };
};
#define PARAMETER public ParameterFigure
class Triangle: PARAMETER{
public:
    double ribLength;
    colors color = red;
};
class Circle: PARAMETER{
    double radius;
    colors color = green;
};
class Square: PARAMETER{

};
int main(){
    ParameterFigure parFigure = ParameterFigure();
    return 0;
}