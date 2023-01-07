#include <iostream>
#include <ctime>
#include <assert.h>
#include "date.h"
#include "client.h"
#include "chambre.h"
#include "hotel.h"
#include "reservation.h"

int main(){
	//----------initialisation----------//
	//init rooms
    Chambre chambre0(01,Type::Single,100);
	std::vector<Chambre> chambres = {chambre0,Chambre(02,Type::Single,100),Chambre(03,Type::Single,100),
									 Chambre(10,Type::Double,125), Chambre(11,Type::Double,125), 
									 Chambre(12,Type::Double,125),Chambre(13,Type::Double,125),
									 Chambre(14,Type::Double,125),Chambre(20,Type::Suite,210),
									 Chambre(21,Type::Suite,210)};

	//init hotel								  
	Hotel Ibis("IBIS01", "Ibis Hotel", "Dijon", chambres);
	std::cout << Ibis;
	std::vector<Hotel> mes_hotels = {Ibis};

	
	//init clients
    Client client1("JB", "Joshua", "De_Belfort");
    display_Client(client1);
	std::vector<Client> mes_clients = {client1, Client("JC", "Julien", "COS"),
									   Client("JPP", "Jean-Pierre", "Polnaref")};

    //init reservation
	Date date1(12,12,2022);
	Date date2(15,1,2023);
	Reservation res1(date1, 7, client1.id(), Ibis.id(),
					 Ibis.chambres().at(0).num(), 
					 Ibis.chambres().at(0).price());
	std::vector<Reservation> reservations = {res1,
											 Reservation(date1, 12, mes_clients.at(1).id(), Ibis.id(), Ibis.chambres().at(3).num(), Ibis.chambres().at(3).price()),
											 Reservation(date2, 14, client1.id(), Ibis.id(), Ibis.chambres().at(8).num(), Ibis.chambres().at(8).price()),
											 Reservation(date1, 14, client1.id(), Ibis.id(), Ibis.chambres().at(9).num(), Ibis.chambres().at(9).price())};
	
	//init others var									 
	std::string id_client;
	Date new_date = Date();
	int nights;
	Type type;
	int numchambre_free;
	int price;

	int num_for_modify;

	int num_for_print;

	int tag;

	int num_for_erase;

	//---------Start---------//
	display_Reservations(reservations);
	
	int choice;
	do{
		std::cout<< "Que souhaitez-vous faire ?"<<std::endl;
	    std::cout<< "Entrer ''1'' pour faire une reservation"<<std::endl;
	    std::cout<< "Entrer ''2'' pour modifier une reservation"<<std::endl;
	    std::cout<< "Entrer ''3'' pour afficher une reservation"<<std::endl;
	    std::cout<< "Entrer ''4'' pour afficher toutes les rerservations d'un client"<<std::endl;
	    std::cout<< "Entrer ''5'' pour annuler une reservation"<<std::endl;
	    std::cin>> choice;
    }while((choice < 1) || (choice > 5));

    switch(choice){
    	case 1 :
			std::cout<< "Creation d'une reservation" << std::endl;

			//search a client
			id_client = enter_Client(mes_clients);

			//enter a date
			new_date = enterDate();

			//enter the numbers of nights for the reservation
			std::cout<< "Entrer le nombre de nuits de votre séjour : "<< std::endl;
			std::cin>> nights;

			//enter the type of room for the reservation
			type = search_Type();

			//search a free room
			numchambre_free = search_Chambre(type, nights, new_date, chambres, reservations);
			
			//create a new reservation
			if (numchambre_free >= 0) {
				for (auto it = chambres.begin(); it != chambres.end(); it++) {
					if (it->num() == numchambre_free) {
						price = it->price();
					}
				}
				std::cout<< "Nouvelle reservation : " << std::endl;
				Reservation new_reservation(new_date, nights, id_client, Ibis.id(), numchambre_free, price);
				reservations.emplace_back(new_reservation);
				std::cout << new_reservation;
			}
    		break;
    	case 2 :
    		//modify a reservation
    		std::cout<< "Entrer le numero de la reservation à modifier (la premere est a 0) : " << std::endl;
    		std::cin>> num_for_modify;
    		reservations.at(num_for_modify) = modify_Res(reservations.at(num_for_modify), mes_clients, chambres, reservations);
			display_Reservations(reservations);
    		break;
    	case 3 :
    		//search a reservation
    		std::cout<<"Entrer le numero de la reservation à afficher (la premere est a 0) : " << std::endl;
    		search_Res(num_for_print, reservations);

    		break;
    	case 4 :
    		//search reservations of a client
    		std::cout<<"Entrer le nom ou l'identifiant du client : " << std::endl;
    		search_Res(tag, reservations);
    		break;
    	case 5 :
    		//erase a reservation
    		std::cout<<"Entrer le numero de la reservation à annuler (la premere est a 0) : " << std::endl;
    		reservations = delete_Res(num_for_erase, reservations);
    		break;

    	default :
    	
    		break;
    }

//-----------End----------//
    return 0;
}
