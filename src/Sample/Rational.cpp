#include <stdexcept>
#include <iostream>
#include "Rational.hpp"

using namespace std;


ostream &operator <<(ostream &os, const Rational &r)
{
	return os << r.m_a << " / " << r.m_b << "=" << static_cast<double>(r.m_a) / r.m_b;
}

Rational::Rational()
{
	m_a = 0;
	m_b = 1;
}

Rational::Rational(int a, int b)
{
	if (b == 0)
		throw invalid_argument("payda sýfýr olamaz!");
	if (b < 0) {
		m_a = -a;
		m_b = -b;
	}
	else {
		m_a = a;
		m_b = b;
	}
	reduce();
}

int Rational::gcd(int a, int b)
{
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

void Rational::reduce()
{
	int gcdnum = gcd(m_a, m_b);

	m_a /= gcdnum;
	m_b /= gcdnum;
}

Rational Rational::operator +(const Rational &r) const
{
	Rational result;

	result.m_a = m_a * r.m_b + m_b * r.m_a;
	result.m_b = m_b * r.m_b;

	result.reduce();

	return result;
}

Rational Rational::operator -(const Rational &r) const
{
	Rational result;

	result.m_a = m_a * r.m_b - m_b * r.m_a;
	result.m_b = m_b * r.m_b;

	result.reduce();

	return result;
}

Rational Rational::operator *(const Rational &r) const
{
	Rational result;

	result.m_a = m_a * r.m_a;
	result.m_b = m_b * r.m_b;

	result.reduce();

	return result;
}

Rational Rational::operator /(const Rational &r) const
{
	Rational result;

	result.m_a = m_a * r.m_b;
	result.m_b = m_b * r.m_a;

	result.reduce();

	return result;
}

Rational &Rational::operator ++()
{
	m_a = m_a + m_b;

	return *this;
}

const Rational Rational::operator ++(int)
{
	Rational temp = *this;

	m_a = m_a + m_b;

	return temp;
}

bool Rational::operator ==(const Rational r) const
{
	return (double)m_a / m_b == (double)r.m_a / r.m_b;
}

bool Rational::operator !=(const Rational r) const
{
	return (double)m_a / m_b != (double)r.m_a / r.m_b;
}

bool Rational::operator >(const Rational r) const
{
	return (double)m_a / m_b > (double)r.m_a / r.m_b;
}

bool Rational::operator <(const Rational r) const
{
	return (double)m_a / m_b < (double)r.m_a / r.m_b;
}

bool Rational::operator >=(const Rational r) const
{
	return (double)m_a / m_b >= (double)r.m_a / r.m_b;
}

bool Rational::operator <=(const Rational r) const
{
	return (double)m_a / m_b <= (double)r.m_a / r.m_b;
}

void Rational::disp() const
{
	cout << m_a;

	if (m_b != 1 && m_a != 0)
		cout << '/' << m_b;
	cout << endl;
}

