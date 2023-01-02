#pragma once
#include <iostream>
#include "date.h"
#include "hotel.h"
#include "client.h"
#include "chambre.h"

class Reservation {
	private:
		int _nights;
		Date _begin;
		int _price;
		int _totalprice;
		std::string _idclient;
		std::string _idhotel;
		int _numchambre;

	public:
		Reservation(Date begin, int nights, 
					std::string idclient, std::string idhotel, int numchambre, int price);
		int getnights();
		int getprice();
		int gettotalprice();
		Date getbegin();
		std::string getidclient();
		std::string getidhotel();
		int getnumchambre();
		void setnights(int nights);
		void setbegin(int new_day, int new_month, int new_year);
};

void search_Res(int num,std::vector<Reservation> reservations);
void search_Res(std::string id_or_name,std::vector<Reservation> reservations,std::vector<Client> clients);
Reservation modify_Res(Reservation& res);
std::vector<Reservation> delete_Res(int num,std::vector<Reservation>& reservations);

std::string display_Res(Reservation res);
std::ostream& operator<<(std::ostream& os, const Reservation& res);
void display_Reservations(std::vector<Reservation> reservations);