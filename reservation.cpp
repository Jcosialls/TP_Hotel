#include <iostream>
#include "reservation.h"

Reservation::Reservation(Date begin, int nights,
	std::string idclient, std::string idhotel, int numchambre, int price) : _begin(begin), _idclient(idclient),
	_idhotel(idhotel), _numchambre(numchambre)
{
	_totalprice = nights * price;
}
int Reservation::getnights() {
	return _nights;
}
int Reservation::gettotalprice() {
	return _totalprice;
}
Date Reservation:: getbegin() {
	return _begin;
}
std::string Reservation::getidclient() {
	return _idclient;
}
std::string Reservation::getidhotel() {
	return _idhotel;
}

int Reservation::getnumchambre() {
	return _numchambre;
}

void Reservation::setnights(int nights) {
	if (nights <= 0) {
		std::cout << "Nombre de nuits invalides" << std::endl;
	}
	else {
		_nights = nights;
	}
}

void Reservation::setbegin(int new_day, int new_month, int new_year) {
	Date(new_day, new_month, new_year);
}