#include <iostream>
#include <ctime>
#include <assert.h>
#include "date.h"
#include "client.h"
#include "chambre.h"
#include "hotel.h"
#include "reservation.h"

int main(){

	//ecriture des chambres
    Chambre chambre0(0,Type::Single,100);
	std::vector<Chambre> chambres = {chambre0,Chambre(1,Type::Single,100),Chambre(2,Type::Single,100),
									 Chambre(10,Type::Double,125), Chambre(11,Type::Double,125), 
									 Chambre(12,Type::Double,125),Chambre(13,Type::Double,125),
									 Chambre(14,Type::Double,125),Chambre(20,Type::Suite,210),
									 Chambre(21,Type::Suite,210)};

	//ecriture des hotels								  
	Hotel Ibis("IBIS01", "Ibis Hotel", "Dijon", chambres);
	std::cout << Ibis;
	std::vector<Hotel> mes_hotels = {Ibis};

	
	//ecriture des clients
    Client client1("JB", "Joshua", "De_Belfort");
    display_Client(client1);
	std::vector<Client> mes_clients = {client1, Client("JC", "Julien", "COS"),
									   Client("JPP", "Jean-Pierre", "Polnaref")};
	entrerClient(mes_clients);

	//ecriture d'une date
	entrerDate();

	int nb_nuits;
	std::cout<< "Entrer le nombre de nuits de votre séjour : ";
	std::cin>> nb_nuits;

	//ecriture d'une reservation
	/*Reservation res1(date1, 7, mes_clients.at(0).id(), mes_hotels.at(0).id(), mes_hotels.at(0).chambres().at(0).num(), mes_hotels.at(0).chambres().at(0).price());
	std::vector<Reservation> reservations = {res1};
	*/
    return 0;
}
