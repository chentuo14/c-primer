#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
public:
    Figure(double x, double y):xSize(x),ySize(y) { }
protected:
    double xSize, ySize;
};

class Figure_2D : public Figure
{
public:
    Figure_2D(double, double);
    virtual double area() = 0;
    virtual double pcrimeter() = 0;
};

class Figure_3D : public Figure
{
public:
    Figure_3D(double , double, double);
    virtual double cubage() = 0;
protected:
    double zSize;
};

class Rectangle : public Figure_2D
{
public:
    Rectangle(double ,double);
    virtual double area();
    virtual double pcrimeter();
};

class Circle : public Figure_2D
{
public:
    Circle(double ,double);
    virtual double area();
    virtual double pcrimeter();
};

class Sphere : public Figure_3D
{
public:
    Sphere(double ,double, double);
    virtual double cubage();
};

class Cone : public Figure_3D
{
public:
    Cone(double ,double, double);
    virtual double cubage();
};

#endif // FIGURE_H
