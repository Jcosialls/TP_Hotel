//---------date.h------
#pragma once
#include <iostream>

//--------------------------------
class Date {
	public:
		Date();
		Date(int day, int month, int year);
		bool isDate(int day, int month);
		int day();
		int month();
		int year();

	private:
		int _day;
		int _month;
		int _year;
		
};

//Fonctions helper
bool isDate(int day, int month);
std::string display_Date(Date date);
std::ostream& operator<<(std::ostream& os, const Date& date);

void entrerDate();
