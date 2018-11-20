#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_
#include <iostream>


class Rational {
	friend std::ostream &operator <<(std::ostream &os, const Rational &r);
public:
	Rational();
	Rational(int a, int b = 1);
	void disp() const;

	Rational operator +(const Rational &r) const;	
	Rational operator -(const Rational &r) const;
	Rational operator *(const Rational &r) const;
	Rational operator /(const Rational &r) const;
	Rational &operator ++();
	const Rational operator ++(int);

	bool operator ==(const Rational r) const;
	bool operator !=(const Rational r) const;
	bool operator >(const Rational r) const;
	bool operator <(const Rational r) const;
	bool operator >=(const Rational r) const;
	bool operator <=(const Rational r) const;
private:
	void reduce();
	static int gcd(int a, int b);

private:
	int m_a;		// pay
	int m_b;		// payda
};

#endif


