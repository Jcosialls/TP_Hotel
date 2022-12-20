#pragma once
#include <iostream>
#include "date.h"
#include "hotel.h"
#include "client.h"
#include "chambre.h"

class Reservation {
	public:
		Reservation(Date begin, int nights, 
					std::string idclient, std::string idhotel, int numchambre, int price);
		int getnights();
		int gettotalprice();
		Date getbegin();
		std::string getidclient();
		std::string getidhotel();
		int getnumchambre();
		void setnights(int nights);
		void setbegin(int new_day, int new_month, int new_year);
	

	private:
		int _nights;
		Date _begin;
		int _totalprice;
		std::string _idclient;
		std::string _idhotel;
		int _numchambre;

};