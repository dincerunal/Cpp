#include "Circle.h"

#include <cmath>

using namespace std;

static const double PI = 3.14;

Circle::Circle(double r) : m_r(fabs(r))
{}
void Circle::SetRadius(double r)
{
	m_r = fabs(r);	
}

double Circle::GetArea() const
{
	return PI * m_r * m_r;
}
double Circle::GetCircumference() const
{
	return 2 * PI * m_r;
}

#if 0

#include <iostream>

void Display(const Circle &r)
{
	cout << "Radius:" << r.GetRadius() << endl;
	cout << "Circumference:" << r.GetCircumference() << endl;
	cout << "Area:" << r.GetArea() << endl;	
}

int main()
{
	Circle c(-3.4);

	Display(c);

	c.SetRadius(4.6);

	Display(c);

	return 0;
}

#endif
