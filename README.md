# Shapes
The university project. Matematics and mechanics department. Goal is to build the hierarchy of class Shape by using inheritance technology.

Hierarchy has the following structure:

Shape ->
    Circle
    Triangle
    Tetragon  ->  Parallelogram  ->  Rectangle  ->  Square
                                     Rhomb      ->      
    Polygon

Class Shape contains 6 fully virtual methods:
	virtual double perimeter() const = 0;
	virtual double area() const = 0;
	virtual void shift(const Point& V) = 0;
	virtual void turn(double q, const Point& G) = 0;
	virtual void print() const = 0;
	virtual void opred() const = 0;
  
These methods are defined in derived classes.
