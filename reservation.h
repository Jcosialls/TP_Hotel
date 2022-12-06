#pragma once
#include "date.h"
#include "hotel.h"
#include "client.h"
#include "chambre.h"

class Reservation {
public:
	Reservation(Date begin, int nights, 
		std::string idclient, std::string idhotel, int numchambre);
	int getnights();
	int gettotalprice();
	int getbegin();
	int getidclient();
	int getidhotel();
	int getnumchambre();


private:
	int _nights;
	Date _begin;
	int _total;
	std::string _idclient;
	std::string _idhotel;
	int _numchambre;


};