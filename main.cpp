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
    Chambre chambre0(01,Type::Single,100);
	std::vector<Chambre> chambres = {chambre0,Chambre(02,Type::Single,100),Chambre(03,Type::Single,100),
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

    //ecriture d'une reservation
	Date date1(12,12,2022);
	Date date2(15,1,2023);
	Reservation res1(date1, 7, client1.id(), Ibis.id(),
					 Ibis.chambres().at(0).num(), 
					 Ibis.chambres().at(0).price());
	std::vector<Reservation> reservations = {res1,
											 Reservation(date1, 12, mes_clients.at(1).id(), Ibis.id(), Ibis.chambres().at(3).num(), Ibis.chambres().at(3).price()),
											 Reservation(date2, 14, client1.id(), Ibis.id(), Ibis.chambres().at(8).num(), Ibis.chambres().at(8).price()),
											 Reservation(date1, 14, client1.id(), Ibis.id(), Ibis.chambres().at(9).num(), Ibis.chambres().at(9).price())};
	
	for(auto i=0; i<reservations.size(); i++){
		std::cout<<reservations.at(i);
	}
	reservations.at(1) = modify_Res(reservations.at(1));
	for(auto i=0; i<reservations.size(); i++){
		std::cout<<reservations.at(i);
	}
/*
	//recherche d'un client
	std::string id_client;
	id_client = entrerClient(mes_clients);

	//entrer une date
	Date newdate= Date();
	newdate = entrerDate();

	//ecriture du nombre de nuits souhaités
	int nb_nuits;
	std::cout<< "Entrer le nombre de nuits de votre séjour : ";
	std::cin>> nb_nuits;

	//ecriture du type de chambre souhaitée
	int type;
	int numchambre_libre;
	int price;
	std::cout<< "Quel type de chambre souhaitez-vous ?"<<std::endl;
	std::cout<< "Entrer ''1'' pour une chambre simple"<<std::endl;
	std::cout<< "Entrer ''2'' pour une chambre double"<<std::endl;
	std::cout<< "Entrer ''3'' pour une suite"<<std::endl;
	std::cin>> type;

	while((type!=1)&&(type!=2)&&(type!=3)){
		std::cout<< "Erreur, ressayez"<<std::endl;
		std::cout<< "Quel type de chambre souhaitez-vous ?"<<std::endl;
		std::cout<< "Entrer ''1'' pour une chambre simple"<<std::endl;
		std::cout<< "Entrer ''2'' pour une chambre double"<<std::endl;
		std::cout<< "Entrer ''3'' pour une suite"<<std::endl;
		std::cin>> type;
	}
	//recherche d'une chambre libre
	switch(type){
        case 1 : 
            numchambre_libre = rechercheChambre(Type::Single, nb_nuits, newdate, chambres, reservations);
            break;
        case 2 :
        	numchambre_libre = rechercheChambre(Type::Double, nb_nuits, newdate, chambres, reservations);
            break;
         case 3 :
        	numchambre_libre = rechercheChambre(Type::Suite, nb_nuits, newdate, chambres, reservations);
            break;
        default :
        	std::cout<<"erreur"<<std::endl;
            break;        
    }
    for(auto i =0; i<chambres.size(); i++){
    	if(chambres.at(i).num()== numchambre_libre){
    		price = chambres.at(i).price();
    	}
    }

    //création de la reservation
    Reservation new_reservation(newdate,nb_nuits,id_client,Ibis.id(),numchambre_libre,price);
    reservations.emplace_back(new_reservation);
    std::cout<<new_reservation;


*/
    return 0;
}
