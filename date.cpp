//----------date.cpp------------

#include <iostream>
#include <ctime>
#include <assert.h>
#include "date.h"


//-----Datevalide-------------
bool Date::isDate(int day, int month) {
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


//-------Date en temps réelle-----
Date::Date() {
	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);
	_year = (now->tm_year + 1900);
	_month = (now->tm_mon + 1);
	_day = now->tm_mday;

}


Date::Date(int day, int month, int year) :
		   _day(day), _month(month), _year(year) {
	bool status = isDate(day, month);
	assert(status && "Date is not valid");
}

int Date::day()const {
	return _day;
}

int Date::month()const {
	return _month;
}

int Date::year()const {
	return _year;
}

 void Date::updateMonth(int month) {
    bool status = isDate(month, _day);
    assert(status == true && "New month is not valid");
    _month = month;
}

void Date::updateDay(int day) {
        bool status = isDate(_month, day);
        assert(status == true && "New day is not valid");
        _day = day;
    }

//--------------Helper Functions-------------//
bool isDate(int day, int month){
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

int getDaysInMonth(int month)  {
    assert(((month >= 1) && (month <= 12)) && "Month is not valid");
    if (month == 2) return 28;
    if ((month == 1 || month == 3 || month == 5 || month == 7
    || month == 8 || month == 10 || month == 12)) return 31;
    return 30;
}

std::string display_Date(Date date) {
	std::string s = std::to_string(date.day()) + "/";
	s += std::to_string(date.month()) + "/";
	s += std::to_string(date.year()) + "\n";
	return s;
}

Date enterDate(){
	int day, month, year;
	bool exist = false;
		std::cout<< "Entrer uniquement le jour d'arrive de votre sejour : ";
		std::cin>> day;
		std::cout<< "Entrer le mois : ";
		std::cin>> month;
		std::cout<< "Entrer l'annee : ";
		std::cin>> year;
		exist = isDate(day,month);
	while(exist!=true){
		std::cout << "Erreur, recommencez" << std::endl;
		std::cout<< "Entrer uniquement le jour d'arrive de votre sejour : ";
		std::cin>> day;
		std::cout<< "Entrer le mois : ";
		std::cin>> month;
		std::cout<< "Entrer l'annee : ";
		std::cin>> year;
		exist = isDate(day,month);
	}
	Date new_date(day,month,year);
	std::cout << new_date;
	return new_date;
}

//--------------Overloading Ops-------------//
Date operator + (const Date& date, const int days) {
    if (days <0) { //if days <0, we call Date - (-days)
        return date - (-days);
    }
    Date tmp(date.day(), date.month(), date.year()); // the current date
    int new_day = tmp.day() + days; // the new day is ok if new_day < end of month
    int new_month = tmp.month();
    int new_year = tmp.year();
    int days_in_month = getDaysInMonth(tmp.month());
    while (new_day > days_in_month) { // end of the month
        new_day -= days_in_month; // the day in the next month
        new_month++;
        if (new_month > 12) { // end of the year
            new_month = 1;
            new_year++;
        }
        //tmp.updateMonth(new_month);
        //days_in_month = getDaysInMonth(tmp.month());
        days_in_month = getDaysInMonth(tmp.month());
    }
    return Date(new_day,new_month, new_year);
}

Date operator + (const int days, const Date& date) {
    return date + days;
}


Date operator - (const Date& date, const int days) {
    if (days <0) { //if days <0, we call Date + (-days)
        return date + (-days);
    }
    int new_year=date.year();
    int new_month=date.month();
    int new_day = date.day()-days; // the new day is ok if > 0
    while (new_day <=0) {
        if (new_month==1) { // beginning of the year
            new_month=12; // in december
            new_year--;
            new_day=31+new_day;
        }else { // other months than january
            int days_in_previous_month = getDaysInMonth(Date(1,new_month-1,new_year).month());
            new_day = days_in_previous_month+new_day;
            new_month--;
        }
    }
    return Date(new_month, new_day, new_year);
}

bool operator == (const Date& d1, const Date& d2)  { // check for equality
    if ((d1.day()==d2.day()) && (d1.month()==d2.month()) && (d1.year()==d2.year())) {
        return true;
    }
    return false;
}

bool operator !=(const Date& d1, const Date& d2)  {
    return !(d1==d2);
}

bool operator < (const Date& d1, const Date& d2) {
	if(d1.year()>d2.year()){
		return false;
	}
	else if(d1.year()<d2.year()){
		return true;
	}
	else if (d1.year()==d2.year()){
		if(d1.month()<d2.month()) {
        	return true;
    	}
    	else if (d1.month()>d2.month()) {
        	return false;
    	}
    	else { // same month
	        if ( d1.day()<d2.day()) {
	            return true;
	        }else {
	            return false;
	        }
	    }
    
    }
    return false;
}


    bool operator > (const Date& d1, const Date& d2) {
        if (d1==d2) {
            return false;
        }
        if (d1<d2) {
            return false;
        }
        return true;
    }

    bool operator <=(const Date& d1, const Date& d2)  {
        if (d1==d2) {
            return true;
        }
        return (d1<d2);
    }

    bool operator >=(const Date& d1, const Date& d2)  {
        if (d1==d2) {
            return true;
        }
        return (d1>d2);
    }

std::ostream& operator<<(std::ostream& os, const Date& date) {
	std::string to_display;
	to_display = display_Date(date);
	os << to_display << std::endl;
	return os;
}

