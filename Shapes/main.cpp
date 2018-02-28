#include "declarations.h"

using namespace std;

int main()
{
#if 1

	// Test 4-angles
	double x, y;
	Point A(0, 4);
	Point B(4, 0);
	Point C(0, -2);
	Point D(-2, -2);
	Point L(-2, 0);
	Point M(4, 0);
	Point N(4, -2);
	Point O(4, 0);

	{
		Shape* m[8];

		Point T(0, 0);        // point of the turn

		m[0] = new Circle(3, O);
		m[1] = new Polygon();
		m[2] = new Tetragon(A, B, C, D);
		m[3] = new Parallelogram(A, B, C, D);
		m[4] = new Rectangle(A, B, C, D);
		m[5] = new Rhomb(A, B, C, D);
		m[6] = new Square(A, B, C, D);
		m[7] = new Triangle(A, B, C);

		for (int i = 0; i < 8; i++)
		{
			print_info(*m[i]);
			//	m[i]->shift({ 1,1 });
			//	print_info(*m[i]);
			//	m[i]->turn(Pi / 2, T);
			//	print_info(*m[i]);
			cout << endl;
		}

		m[3] = m[6];
		m[3]->opred();
	}

	{
		// Test Polygon
		Polygon PP;
		PP.insert_end(A);
		PP.insert_end(B);
		PP.insert_end(C);
		PP.insert_end(D);
		PP.insert_end(L);
		PP.insert_end(M);
		PP.insert_end(O);

		print_info(PP);

		Polygon a;
		cout << "How much vertices?\n";
		int n;
		cin >> n;
		cout << "Enter them:\n";
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", &x);
			scanf("%lf", &y);
			Point F(x, y);
			a.insert_end(F);
		}
		print_info(a);
		a.shift({ 2, 2 });
		print_info(a);
		cout << "Enter point of turn:\n";
		scanf("%lf", &x);
		scanf("%lf", &y);
		Point T(x, y);

		a.turn(Pi, T);
		print_info(a);
	}

	{
		cout << "Enter 4 points\n";

		scanf("%lf", &x);
		scanf("%lf", &y);
		Point A(x, y);

		scanf("%lf", &x);
		scanf("%lf", &y);
		Point B(x, y);

		scanf("%lf", &x);
		scanf("%lf", &y);
		Point C(x, y);

		scanf("%lf", &x);
		scanf("%lf", &y);
		Point D(x, y);

		cout << "\n";

		Square e(A, B, C, D);
		print_info(e);

		e.shift({ 1, 1 });
		print_info(e);

		cout << "Enter point of turn:\n";
		scanf("%d", &x);
		scanf("%d", &y);
		Point T(x, y);

		e.turn(Pi, T);
		print_info(e);

		system("pause");
	}
	{
		// Check Circle
		double r;

		cout << "Enter center and radius:\n";
		scanf("%lf", &x);
		scanf("%lf", &y);
		Point D(x, y);
		scanf("%lf", &r);

		Circle t(r, D);
		print_info(t);
		t.shift({ 5,5 });
		print_info(t);

		cout << "Enter point of turn:\n";
		scanf("%lf", &x);
		scanf("%lf", &y);
		Point T(x, y);
		t.turn(Pi, T);

		print_info(t);

	}

	// Test Triangle

	{
		cout << "Enter 3 points\n";

		scanf("%lf", &x);
		scanf("%lf", &y);
		Point A(x, y);

		scanf("%lf", &x);
		scanf("%lf", &y);
		Point B(x, y);

		scanf("%lf", &x);
		scanf("%lf", &y);
		Point C(x, y);

		cout << "\n";

		Triangle e(A, B, C);
		print_info(e);
		e.shift({ 1,1 });
		print_info(e);

		cout << "Enter point of turn:\n";
		scanf("%lf", &x);
		scanf("%lf", &y);
		Point T(x, y);

		e.turn(Pi, T);
		print_info(e);
	}
#endif
	system("pause");
	return 0;
}



