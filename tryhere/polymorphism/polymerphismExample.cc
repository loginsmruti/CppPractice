#include<iostream>

class Shape
{
  private:
    int area;
  
  public:
    Shape(int x) : area(x)
    { }

  virtual int getArea() {
    return area;
  }
};

class Circle : public Shape
{

  //private:
  //  int radius;
  
  public:
  
  int radius;

    Circle(int x) 
    : Shape(x),
      radius(x)
  { }

  int getArea() {
    std::cout << "in Circle" << std::endl;
    return radius*radius;
  }
};

int main(int argc , char* argv[])
{
  Shape *shape = new Circle(6);
  
  
  int area = shape->getArea();

  Circle *c = dynamic_cast<Circle*>(shape);

  std::cout << "Radius : " << c->radius << "Area : " << area << std::endl;

  return 0;
}
