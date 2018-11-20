#ifndef COMPLEX_HPP_
#define COMPLEX_HPP_

#include <iostream>
#include <cmath>

class Complex {
	friend std::ostream &operator <<(std::ostream &os, const Complex &r);
	friend std::istream &operator >>(std::istream &is, Complex &r);
	friend Complex operator +(double x, const Complex &r);
	friend Complex operator *(double x, const Complex &r);
	friend Complex operator -(double x, const Complex &r);
public:
	Complex();
	Complex(double real, double imag = 0);
public:
	double &Real() { return  m_real; }
	const double &Real() const { return  m_real; }
	double &Imag() { return  m_imag; }
	const double &Imag() const { return  m_imag; }
	double Norm() const;
public:
	void disp() const;
public:	
	Complex operator +(const Complex &x) const;
	Complex operator +(double x) const;
	Complex operator -(const Complex &x) const;
	Complex operator *(const Complex &x) const;
	Complex operator -() const;
	Complex &operator ++();			// prefix
	const Complex operator ++(int);	// postfix
	void operator()() const;
	explicit operator double() const;
private:
	double m_real, m_imag;
};

#endif

