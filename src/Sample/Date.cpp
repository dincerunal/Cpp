#include "Date.h"

Date::Date(int day, int mon, int year)
{
	//...
	m_day = day;
	m_mon = mon;
	m_year = year;
}

void Date::SetDay(int day)
{
	//...
	m_day = day;
}
void Date::SetMonth(int mon)
{
	//...
	m_mon = mon;
}
void Date::SetYear(int year)
{
	//...
	m_year = year;
}

#if 0
#include <iostream>

using namespace std;

int main()
{
	Date d(10, 9, 1976);

	cout << d.GetDay() << "/" << d.GetMonth() << "/" << d.GetYear() << endl;

	d.SetDay(11);
	d.SetMonth(7);
	d.SetYear(1983);

	cout << d.GetDay() << "/" << d.GetMonth() << "/" << d.GetYear() << endl;


	return 0;
}

#endif