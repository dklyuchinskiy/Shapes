#pragma once

#include "library.h"
using namespace std;

class Point
{
public:
	Point();
	Point(double x1, double y1);

	void shift(double koordX, double koordY);
	void turn(double q, const Point& G);
	void info() const;

	double getX() const { return x; };
	double getY() const { return y; };

private:
	double x;
	double y;
};

class Shape
{
public:
	virtual double perimeter() const = 0;
	virtual double area() const = 0;
	virtual void shift(const Point& V) = 0;
	virtual void turn(double q, const Point& G) = 0;
	virtual void print() const = 0;
	virtual void opred() const = 0;

};

class Circle : public Shape
{
public:
	Circle();
	Circle(double r, Point a);
	double perimeter() const;
	double area() const;
	void print() const;
	void shift(const Point& V);
	void turn(double q, const Point& G);
	void opred() const;

private:
	double radius;
	Point center;
	const string type = "Circle";
};

class Triangle : public Shape  
{
public:
	Triangle(Point p1, Point p2, Point p3);

	double perimeter() const;
	double area() const;
	void shift(const Point& V);    // across point V
	void turn(double q, const Point& G); // on angle q, around point G
	void print() const;
	void opred() const;

private:
	Point top1;
	Point top2;
	Point top3;
	const string type = "Triangle";
};

class Tetragon : public Shape
{
public:
	Tetragon(Point p1, Point p2, Point p3, Point p4);

	double perimeter() const;
	double area() const;
	void shift(const Point& V);    // across point V
	void turn(double q, const Point& G); // on angle q, around point G
	void print() const;
	void opred() const;

private:
	Point top1;
	Point top2;
	Point top3;
	Point top4;
	const string type = "Tetragon";
};

class Parallelogram : public Tetragon
{
public:
	Parallelogram(Point p1, Point p2, Point p3, Point p4) : Tetragon(p1, p2, p3, p4), top1(p1), top2(p2), top3(p3), top4(p4) {}
	void opred() const { cout << type << endl; }
private:
	Point top1;
	Point top2; 
	Point top3; 
	Point top4;
	const string type = "Parallelogram";
};

class Rectangle : virtual public Parallelogram 
{
public:
	Rectangle(Point p1, Point p2, Point p3, Point p4) : Parallelogram(p1, p2, p3, p4), top1(p1), top2(p2), top3(p3), top4(p4) {}
	void opred() const { cout << type << endl; }
private:
	Point top1;
	Point top2;
	Point top3;
	Point top4;
	const string type = "Rectangle";
};

class Rhomb : virtual public Parallelogram
{
public:
	Rhomb(Point p1, Point p2, Point p3, Point p4) : Parallelogram(p1, p2, p3, p4), top1(p1), top2(p2), top3(p3), top4(p4) {}
	void opred() const { cout << type << endl; }
private:
	Point top1;
	Point top2;
	Point top3;
	Point top4;
	const string type = "Rhomb";
};

class Square : public Rhomb, public Rectangle  // у производного класса может быть несколько родителей, квадрат сделан +
{
public:
	Square(Point p1, Point p2, Point p3, Point p4) : Parallelogram(p1, p2, p3, p4), Rhomb(p1, p2, p3, p4), Rectangle(p1, p2, p3, p4), top1(p1), top2(p2), top3(p3), top4(p4) {}
	//¬озникает проблема, конструкторы B и C могут вызывать различные конструкторы A и с различными параметрами. 
	//¬ итоге в конструкторе квадрата мы должны €вно вызвать конструктор параллелограмма, а в конструкторах пр€моугольника и ромба он опуститьс€!!!!
	//¬ св€зи с этим есть замечание: Ќужно следить и понимать, что при виртуальном наследовании в конструкторах B и C может не вызватьс€ конструктор A с разными параметрами. 
	void opred() const { cout << type << endl; }
private:
	Point top1;
	Point top2;
	Point top3;
	Point top4;
	const string type = "Square";
};

class Polygon : public Shape
{
public:
	class Node
	{
	public:
		Node(Point d) : data(d), next(0) {}

		Point data; // point is a data of the node
		Node* next;
	};

	Polygon() : head(0) {}

	double perimeter() const;
	double area() const;
	void insert_end(Point v);
	void shift(const Point& V);
	void turn(double q, const Point& G);
	void print() const;
	void opred() const { cout << type << endl; }

private:
	Node* head;
	const string type = "Polygon";
};


void print_info(Shape& p);
double geron(double s1, double s2, double s3);
double side(Point top1, Point top2);
