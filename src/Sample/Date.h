#ifndef DATE_H_
#define DATE_H_

class Date {
public:
	Date(int day, int mon, int year);
public:
	void SetDay(int day);
	void SetMonth(int mon);
	void SetYear(int year);
	int GetDay() const { return m_day; }
	int GetMonth() const { return m_mon; }
	int GetYear() const { return m_year; }
	int GetDayOfYear() const { return m_dayOfYear; }
private:
	int m_day, m_mon, m_year;
	int m_dayOfYear;
};

#endif //DATE_H_
