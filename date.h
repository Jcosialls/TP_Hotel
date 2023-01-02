//---------date.h------
#pragma once
#include <iostream>

//--------------------------------
class Date {
	public:
		Date();
		Date(int day, int month, int year);
		bool isDate(int day, int month);
		int day()const;
		int month()const;
		int year()const;
		void updateMonth(int month);
		void updateDay(int day);

	private:
		int _day;
		int _month;
		int _year;
		
};

//---------Fctons Helpers-----------//
bool isDate(int day, int month);
int getDaysInMonth(int month);
std::string display_Date(Date date);
Date entrerDate();

//-----------operators-------------//
bool operator == (const Date& d1, const Date& d2); // d1 == d2
bool operator != (const Date& d1, const Date& d2); // d1 != d2
bool operator < (const Date& d1, const Date& d2) ;  // d1 <  d2
bool operator > (const Date& d1, const Date& d2) ;  // d1 >  d2
bool operator <= (const Date& d1, const Date& d2) ; // d1 <= d2
bool operator >= (const Date& d1, const Date& d2) ; // d1 <= d2

Date operator + (const Date& date, const int days); // date + integer
Date operator + (const int days, const Date& date); // integer + date
Date operator - (const Date& date, const int days); // date - integer
std::ostream& operator<<(std::ostream& os, const Date& date);
