#include <iostream>
#include "Cube.h"
#include "Circle.h"
#include "point.h"

using namespace std;

void isInCircle(const point &p, const Circle &c)
{
	int distance = (c.getCenter().getX() - p.getX()) ^ 2 + (c.getCenter().getY() - p.getY()) ^ 2;
	int r2 = c.getR() * c.getR();
	if (distance == r2)
	{
		cout << "��Բ��" << endl;
	}
	else if (distance > r2)
	{
		cout << "Բ��" << endl;
	}
	else
	{
		cout << "Բ��" << endl;
	}

}

int main()
{
	point p;
	p.setPoint(10, 10);
	point center;
	center.setPoint(10, 0);
	Circle c;
	c.setCenter(center);
	isInCircle(p, c);

	
	system("pause");
}