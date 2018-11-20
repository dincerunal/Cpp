#include <iostream>
#include <cmath>
#include "Complex.hpp"

using namespace std;

ostream &operator<<(ostream &os, const Complex &r)
{
	os << r.m_real;
	if (r.m_imag != 0) {
		os << (r.m_imag < 0 ? "-" : "+");
		if (fabs(r.m_imag) != 1)
			os << fabs(r.m_imag);
		os << "i";
	}

	return os;
}

istream &operator >>(istream &is, Complex &r)
{
	return is >> r.m_real >> r.m_imag;
}

Complex operator +(double x, const Complex &r)
{
	return r + x;
}

Complex operator *(double x, const Complex &r)
{
	return r * x;
}

Complex operator -(double x, const Complex &r)
{
	return x + -r;
	//return -1 * (r - x);
}

Complex::Complex() 
{
	m_real = m_imag = 0;
}

Complex::Complex(double real, double imag)
{
	m_real = real;
	m_imag = imag;
}

inline double Complex::Norm() const 
{
	return sqrt(m_real * m_real + m_imag * m_imag);
}

void Complex::disp() const
{
	cout << m_real;
	if (m_imag != 0) {
		cout << (m_imag < 0 ? "-" : "+");
		if (fabs(m_imag) != 1)
			cout << fabs(m_imag);
		cout << "i";
	}
	cout << endl;
}

Complex Complex::operator +(const Complex &x) const
{
	Complex result;

	result.m_real = m_real + x.m_real;
	result.m_imag = m_imag + x.m_imag;
	
	return result;
}

Complex Complex::operator +(double x) const
{
	Complex result;

	result.m_real = m_real + x;
	result.m_imag = m_imag;

	return result;
}

Complex Complex::operator -(const Complex &x) const
{
	Complex result;

	result.m_real = m_real - x.m_real;
	result.m_imag = m_imag - x.m_imag;

	return result;
}

Complex Complex::operator *(const Complex &x) const
{
	Complex result;

	result.m_real = m_real * x.m_real - m_imag * x.m_imag;
	result.m_imag = m_real * x.m_imag + m_imag * x.m_real;

	return result;
}

Complex Complex::operator -() const
{
	Complex result;

	result.m_real = -m_real;
	result.m_imag = -m_imag;

	return result;
}

Complex &Complex::operator ++()
{
	++m_real;

	return *this;
}

const Complex Complex::operator ++(int)
{
	Complex result = *this;

	++m_real;

	return result;
}

void Complex::operator()() const
{
	cout << *this << endl;
}

Complex::operator double() const
{
	return Norm();
}


