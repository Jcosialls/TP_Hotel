//---------date.h------
#pragma once
#include <iostream>

//--------------------------------
class Date {
	public:
		Date();
		Date(int day, int month, int year);
		int day();
		int month();
		int year();

	private:
		int _day;
		int _month;
		int _year;
		bool isDate(int day, int month, int year);
};

//Fonctions helper
std::string display_Date(Date date);
std::ostream& operator<<(std::ostream& os, const Date& date);
