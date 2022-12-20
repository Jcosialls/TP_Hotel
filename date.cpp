//----------date.cpp------------

#include <iostream>
#include <ctime>
#include <assert.h>
#include "date.h"

//-------Date en temps réelle-----
Date::Date() {
	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);
	_year = (now->tm_year + 1900);
	_month = (now->tm_mon + 1);
	_day = now->tm_mday;

}


//-----Datevalide-------------
bool Date::isDate(int day, int month, int year) {
	if ((day < 1) || (day > 31))
		return false;

	if ((month < 1) || (month > 12))
		return false;

	if ((month == 2) && (month > 28))
		return false;

	if (((month == 4) || (month == 11) || (month == 9)) && (day > 30))
		return false;
	return true;
}

Date::Date(int day, int month, int year) :
	_day(day),
	_month(month),
	_year(year) {
	bool status = isDate(day, month, year);
	assert(status && "Date is not valid");
}

int Date::day() {
	return _day;
}

int Date::month() {
	return _month;
}

int Date::year() {
	return _year;
}
//fonctions Helper
std::string display_Date(Date date) {
	std::string s = std::to_string(date.day()) + "/" + std::to_string(date.month()) + "/" + std::to_string(date.year()) + "\n";
	return s;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
	std::string to_display;
	to_display = display_Date(date);
	os << to_display << std::endl;
	return os;
}