#ifndef CIRCLE_H_
#define CIRCLE_H_

class Circle {
public:
	Circle(double r = 0.0);
	void SetRadius(double r);
	double GetRadius() const { return m_r; }
	double GetArea() const;
	double GetCircumference() const;
private:
	void calculate();
private:
	double m_r;	
};


#endif

