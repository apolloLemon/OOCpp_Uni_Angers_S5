#pragma once

struct Color {
	unsigned short r,g,b;
};

class Point {
	int _x,_y;
	Color c;
	
	Point();
	Point(int, int);
	Point(const Point &);

	bool Equal();
	void Translate();
};

class Shape {
	Point _o;
	
	Shape();
	bool EqualOrigin();
	void Translate();
};
class Segment : Shape {
	Point _end;
};
class Triangle : Shape {
	Point _p1,_p2;
};
class Rectangle : Shape {
	Point _p1, _P2, _p3;
	bool isSquare();
};
class Text : Shape {};