/*
 * shape.cc
 *
 *  Created on: Dec 11, 2016
 *      Author: smruti
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <set>


using namespace std;

class Shape;

typedef std::set<Shape *> ShapeVector;

class Shape {
    double width;
    double height;

    char name[20];
    public:
    Shape() {
        width = height = 0.0;
        strcpy(name, "unknown");
    }

    Shape(double w, double h, char *n) {
        width = w;
        height = h;
        strcpy(name, n);
    }

    Shape(double x, char *n) {
        width = height = x;
        strcpy(name, n);
    }

    void display() {
        cout << "Width and height are " << width << " and " << height << "\n";
    }

    double getWidth() { return width; }
    double getHeight() { return height; }
    void setWidth(double w) { width = w; }
    void setHeight(double h) { height = h; }
    char *getName() { return name; }

    virtual double area() {
        cout << "Error: area() must be overridden.\n";
        return 0.0;
    }

};

class Triangle : public Shape {
    char style[20];
    public:

    Triangle() {
        strcpy(style, "unknown");
    }

    Triangle(char *str, double w, double h) : Shape(w, h, "triangle") {
        strcpy(style, str);
    }

    Triangle(double x) : Shape(x, "triangle") {
        strcpy(style, "isosceles");
    }

    double area() {
        return getWidth() * getHeight() / 2;
    }

    void showStyle() {
        cout << "Triangle is " << style << "\n";
    }
};

class Rectangle : public Shape {
    public:

        Rectangle(double w, double h) : Shape(w, h, "rectangle") { }

        Rectangle(double x) : Shape(x, "rectangle") { }

        bool isSquare() {
            if(getWidth() == getHeight())
                return true;
            return false;
        }

        double area() {
            return getWidth() * getHeight();
        }
};

int main() {

    
    ShapeVector shapeVector;
    //shapeVector.reserve(5);

    Shape *shape0 = new Triangle("right", 8.0, 12.0);
    Shape *shape1 = new Rectangle(10);
    Shape *shape2 = new Rectangle(10, 4);
    Shape *shape3 = new Triangle(7.0);
    Shape *shape4 = new Shape(10, 20, "generic");

    //shapeVector.push_back(shape0);
    //shapeVector.push_back(shape1);
    //shapeVector.push_back(shape2);
    //shapeVector.push_back(shape3);
    //shapeVector.push_back(shape4);

    shapeVector.insert(shape0);
    shapeVector.insert(shape1);
    shapeVector.insert(shape2);
    shapeVector.insert(shape3);
    shapeVector.insert(shape4);


    return 0;
}

