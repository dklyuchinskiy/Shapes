#include "declarations.h"
using namespace std;


// Definitions for class Point

Point::Point() : x(0), y(0) {}

Point::Point(double x1, double y1) : x(x1), y(y1) { }

void Point::shift(double koordX, double koordY) 
{
	x = x + koordX;
	y = y + koordY;
}

void Point::turn(double q, const Point& G) 
{
	double t;
	x = x - G.x;       //  переходим в новую систему отсчета
	y = y - G.y;
	t = x;
	x = x * cos(q) - y * sin(q);   // поворот относительно центра
	y = t * sin(q) + y * cos(q);
	x = x + G.x;               // обратный переход в старую систему
	y = y + G.y;
}

void Point::info() const
{
	cout << "X:" << x << " Y:" << y << "\n";
}


// Definitions for class Circle

Circle::Circle() : radius(0), center(0,0) { }
Circle::Circle(double r, Point a) : radius(r), center(a) { }
double Circle::perimeter() const { return 2 * Pi * radius; }
double Circle::area() const { return Pi * radius * radius; }
void Circle::opred() const { cout << type << endl; }

void Circle::print() const
{
	cout << "Coordinates of center:\n";
	center.info();
	cout << "Radius: " << radius << "\n";
}

void Circle::shift(const Point& V)
{
	center.shift(V.getX(), V.getY());
}

void Circle::turn(double q, const Point& G)
{
	center.turn(q, G);
}

// Definitions for class Triangle

Triangle::Triangle(Point p1, Point p2, Point p3) : top1(p1), top2(p2), top3(p3) { }
void Triangle::opred() const { cout << type << endl; }

double Triangle::perimeter() const
{
	return side(top1, top2) + side(top2, top3) + side(top3, top1);
}

double Triangle::area() const
{
	return geron(side(top1, top2), side(top2, top3), side(top3, top1));
}

void Triangle::shift(const Point& V)
{
	top1.shift(V.getX(), V.getY());
	top2.shift(V.getX(), V.getY());
	top3.shift(V.getX(), V.getY());
}

void Triangle::turn(double q, const Point& G)  
{
	top1.turn(q, G);
	top2.turn(q, G);
	top3.turn(q, G);
}

void Triangle::print() const
{
	cout << "Coordinates top1:\n";  
	top1.info();
	cout << "Coordinates top2:\n";
	top2.info();
	cout << "Coordinates top3:\n";
	top3.info();

	cout << "The first side: " << side(top1, top2) << endl;
	cout << "The second side: " << side(top2, top3) << endl;
	cout << "The third side: " << side(top3, top1) << endl;
}

// Definitions for class Tetragon

Tetragon::Tetragon(Point p1, Point p2, Point p3, Point p4) : top1(p1), top2(p2), top3(p3), top4(p4) { }
void Tetragon::opred() const { cout << type << endl; }

double Tetragon::perimeter() const
{
	return side(top1, top2) + side(top2, top3) + side(top3, top4) + side(top4, top1);
}

double Tetragon::area() const
{
	return geron(side(top1, top2), side(top2, top3), side(top1, top3))
		 + geron(side(top3, top4), side(top4, top1), side(top1, top3));
}

void Tetragon::shift(const Point& V)
{
	top1.shift(V.getX(), V.getY());
	top2.shift(V.getX(), V.getY());
	top3.shift(V.getX(), V.getY());
	top4.shift(V.getX(), V.getY());
}

void Tetragon::turn(double q, const Point& G)  
{
	top1.turn(q, G);
	top2.turn(q, G);
	top3.turn(q, G);
	top4.turn(q, G);
}

void Tetragon::print() const
{
	cout << "Coordinates top1:" << endl; 
	top1.info();
	cout << "Coordinates top2:" << endl;
	top2.info();
	cout << "Coordinates top3:" << endl;
	top3.info();
	cout << "Coordinates top4:" << endl;
	top4.info();

	cout << "The first side: " << side(top1, top2) << endl;
	cout << "The second side: " << side(top2, top3) << endl;
	cout << "The third side: " << side(top3, top4) << endl;
	cout << "The forth side: " << side(top4, top1) << endl;
}


// Definitions for class Polygon

void Polygon::insert_end(Point v)  //функция добавления вершин в многоульник
{
	Node* cur = head;
	Node* nl = new Node(v);
	if (head == NULL)
	{
		head = nl;
		return;
	}
	while (cur->next != NULL) cur = cur->next;
	cur->next = nl;
}

double Polygon::perimeter() const
{
	Node* cur = head;
	Node* prev;

	double per = 0;

	if (head == 0) return 0;
	while (cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
		per += side(cur->data, prev->data);
	}
	per += side(head->data, cur->data);
	return per;
}

double Polygon::area() const
{
	Node* cur = head;
	Node* prev;
	double S = 0;
	double side1, side2, side3;

	if (head == NULL) return 0;
	cur = cur->next;
	while (cur->next != 0)
	{
		prev = cur;
		cur = cur->next;
		side1 = side(head->data, prev->data);
		side2 = side(prev->data, cur->data);
		side3 = side(cur->data, head->data);
		S += geron(side1, side2, side3);
	}
	return S;
}

void Polygon::shift(const Point& V)
{
	Node* cur = head;
	if (head == NULL) return;

	cur->data.shift(V.getX(), V.getY()); // shift the first node
	while (cur->next != NULL)
	{
		cur = cur->next;
		cur->data.shift(V.getX(), V.getY());
	}
}

void Polygon::turn(double q, const Point& G)
{
	Node* cur = head;
	if (head == NULL) return;

	cur->data.turn(q, G); // turn the first node
	while (cur->next != NULL)
	{
		cur = cur->next;
		cur->data.turn(q, G);
	}
}

void Polygon::print() const
{
	Node* cur = head;
	Node* prev;
	if (head == 0) return;

	cout << "Top's coordinates:" << endl;
	head->data.info();
	while (cur->next != NULL)
	{
		cur = cur->next;
		cur->data.info();
	}

	cout << "Sides:" << endl;
	cur = head;
	while (cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
		cout << side(prev->data, cur->data) << endl;
	}
	cout << side(head->data, cur->data) << endl;
}


void print_info(Shape& p)           // печать информации  - в параметр подставляется производный класс, пользовательская функция
{
	cout << "Area: " << p.area() << endl;        
	cout << "Perimetr: " << p.perimeter() << endl;   
	p.print(); //виртуальный                 //вершины и стороны
			   //в каждом производном классе - свой                 //print - виртуальная метод, применяется к элементу базового класса Shape;
			   // функция print_info принимает ссылку на класс Shape, но работает с производным классом, т.к. функция принт, которая внутри искомой, виртуальная

	p.opred();
	cout << endl;
}

double geron(double s1, double s2, double s3)
{
	double pp = (s1 + s2 + s3) / 2.0;
	return sqrt(pp*(pp - s1)*(pp - s2)*(pp - s3));
}

double side(Point top1, Point top2)
{
	double x = top1.getX() - top2.getX();
	double y = top1.getY() - top2.getY();

	return sqrt(x * x + y * y);
}