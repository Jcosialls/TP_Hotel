#include <iostream>
#include <assert.h>
#include "reservation.h"

Reservation::Reservation(Date begin, int nights,
	std::string idclient, std::string idhotel, int numchambre, int price) : _begin(begin), _nights(nights), _idclient(idclient),
	_idhotel(idhotel), _numchambre(numchambre), _price(price)
{
	bool status = false;
	if(nights >= 0){
	_totalprice = nights * price;
	status = true;
	}else{
		status = false;
	}
	assert(status && "number of nights is not valid");
}
int Reservation::getnights() {
	return _nights;
}
int Reservation::getprice() {
	return _price;
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


//--------------Helper Functions-------------//

void search_Res(int num,std::vector<Reservation> reservations){
	std::cout<<reservations.at(num);
}


void search_Res(std::string id_or_name,std::vector<Reservation> reservations,std::vector<Client> clients){
	for(auto it = clients.begin(); it!=clients.end(); it++){
		if((id_or_name == it->lastname())||(id_or_name == it->id())){
			id_or_name = it->id();
		}
	}
	for(auto i = 0; i<reservations.size(); i++){
		if(id_or_name == reservations.at(i).getidclient()){
			std::cout<<reservations.at(i);
		}
	}
}		

Reservation modify_Res(Reservation& res, std::vector<Client> clients,
					   std::vector<Chambre> chambres,std::vector<Reservation> reservations){
	int modify;
	Date new_date = Date();
	std::string new_id_client;
	
	std::cout<<"Que voulez-vous modifier ?"<< std::endl;
	std::cout<<"entrer '1' pour modifier la date d'arrivee"<< std::endl;
	std::cout<<"entrer '2' pour modifier le nombre de nuits du sejour"<< std::endl;
	std::cout<<"entrer '3' pour modifier le client"<< std::endl;
	std::cout<<"entrer '4' pour modifier le type de chambre souhaite"<< std::endl;
	std::cin>>modify;
	
	switch(modify){
        case 1 : 
        	new_date = enterDate();
        	return Reservation(new_date,res.getnights(),res.getidclient(),res.getidhotel(),res.getnumchambre(),res.getprice());
            break;
        case 2 :
        	int new_nights;
			do{
				std::cout<< "Entrer le nombre de nuits de votre séjour : ";
				std::cin>> new_nights;
			}while(new_nights <= 0);
			return Reservation(res.getbegin(),new_nights,res.getidclient(),res.getidhotel(),res.getnumchambre(), res.getprice());
            break;
        case 3 : 
        	new_id_client = enter_Client(clients);
        	return Reservation(res.getbegin(),res.getnights(),new_id_client,res.getidhotel(),res.getnumchambre(), res.getprice());
            break;
        case 4 : 
	        Type type;
	    	int new_number;
	    	int new_price;
        	type = search_Type();
        	new_number = search_Chambre(type, res.getnights(), res.getbegin(), chambres, reservations);
        	if(new_number == -1){
        		std::cout<<"la reservation n'est pas modifier" <<std::endl;
        	}else{
        		for (auto it = chambres.begin(); it != chambres.end(); it++) {
					if (it->num() == new_number) {
						new_price = it->price();
					}
				}
        		return Reservation(res.getbegin(),res.getnights(),res.getidclient(),res.getidhotel(),new_number, new_price);
        	}
            break;
        default :
        	return res;
            break;        
    }
}

std::vector<Reservation> delete_Res(int num,std::vector<Reservation>& reservations){
	if(num >= 0){
		reservations.erase(reservations.begin() + num);
	}
	return reservations;
}
	
std::string display_Res(Reservation res){
	std::string s = "Reservation [ ""id client : " + res.getidclient() + "\t";
	s+="id hotel : " + res.getidhotel() + "\t";
	s+="num de chambre : " + std::to_string(res.getnumchambre()) + "\t";
	s+="date d'arrivee : " + display_Date(res.getbegin());
	s+="nombres de nuits : " + std::to_string(res.getnights());
	s+=" ]";
	return s;
}

void display_Reservations(std::vector<Reservation> reservations){
	for(auto it = reservations.begin(); it != reservations.end(); it++){
		std::cout<<*it << std::endl;
	}
}

//--------------Overloading Ops-------------//
std::ostream& operator<<(std::ostream& os, const Reservation& res){
	std::string to_display;
		to_display = display_Res(res);
		os << to_display << std::endl;
		return os;
}

