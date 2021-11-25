#include <iostream>
#include <cassert>
#include <cmath>
class GeneralParameter{
    double coordinatesCenter[2] = {0,0};
public:
    int num;
    enum colors{
        null,
        red,
        blue,
        green,
        yellow,
    };
    void setCoordinates(){
        double x;
        double y;
        std::cout << "Enter x,y\n";
        std::cin >> x >> y;
        assert(x >= 0 && y >= 0);
        coordinatesCenter[0] = x;
        coordinatesCenter[1] = y;
    }
    double* getArrCoord(){
        return coordinatesCenter;
    }
};
#define GENERAL public GeneralParameter
class Triangle: GENERAL{
    double ribLength;
    colors color = red;
public:
    double getSquare(){
        return (pow(ribLength, 2) * sqrt(3)) / 4;
    }
    double getDescribing(){
        return ribLength * 2;
    }
    void setParameter(){
        std::cout << "Enter coordinates\n";
        setCoordinates();
        std::cout << "Enter rib\n";
        std::cin >> ribLength;
        assert(ribLength >= 0);
    }
};
class Circle: GENERAL{
    double radius;
    colors color = green;
public:
    void setParameter(){
        std::cout << "Enter coordinates\n";
        setCoordinates();
        std::cout << "Enter radius\n";
        std::cin >> radius;
        assert(radius >= 0);
    }
    double getSquare(){
        return M_PI * pow(radius, 2);
    }
    double getDescribing(){
        return radius * 4;
    }
};
class Square: GENERAL{
    double ribLength;
    colors color = blue;
public:
    void setParameter(){
        std::cout << "Enter coordinates\n";
        setCoordinates();
        std::cout << "Enter ribLength\n";
        std::cin >> ribLength;
        assert(ribLength >= 0);
    }
    double getSquare(){
        return ribLength * 2;
    }
    double getDescribing(){
        return ribLength * 2;
    }
};
class Rectangle: GENERAL{
    double height;
    double width;
    colors color = yellow;
public:
    void setParameter(){
        std::cout << "Enter coordinates\n";
        setCoordinates();
        std::cout << "Enter height, width\n";
        std::cin >> height >> width;
        assert(height >= 0 && width >= 0);
    }
    double getSquare(){
        return height * width;
    }
    double getDescribing(){
        return height * width;
    }
};
#define FIGURE(figure) \
    (figure).setParameter();\
    std::cout << "square " << (figure).getSquare() << std::endl;\
    std::cout << "describing " << (figure).getDescribing() << std::endl;
int main(){
    Triangle triangle = Triangle();
    Circle circle = Circle();
    Square square = Square();
    Rectangle rectangle = Rectangle();
    std::string action;

    while (action != "exit"){
        std::cout << "Enter action\n";
        std::cin >> action;
        if (action == "circle"){
            FIGURE(circle)
        }else if (action == "triangle"){
           FIGURE(triangle)
        }else if (action == "square"){
            FIGURE(square)
        }else if (action == "rectangle"){
            FIGURE(rectangle)
        }
    }
    return 0;
}