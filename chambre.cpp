#include <iostream>
#include <cassert>
#include <vector>
#include "chambre.h"
#include "reservation.h"


Chambre::Chambre(int num, Type type, int price):
    _num(num), _type(type), _price(price){
       bool status = isChambre(num,price);
       if(status!=true)
       assert(status && "Chambre is not valid"); 
    }

bool Chambre::isChambre(int num, int price){
    if(num <0)  return false;
    if(price<0) return false;
    return true;
}    

int Chambre::num()const{
    return _num;
}
Type Chambre::type()const{
    return _type;
}
int Chambre::price()const{
    return _price;
}

void Chambre::setprice(int price) {
	if (price >= 0)
		_price = price;
	else
		std::cout << "prix entré non valide, entrer un prix valide"<<std::endl ;
}

std::string display_Chambre(Chambre chambre){
    std::string s = "Chambre num " + std::to_string(chambre.num()) +"\tType de chambre : ";
    switch(chambre.type()){
        case Type::Single :
            s += "Chambre simple lit";
            break;
        case Type::Double :
			s += "Chambre double lit";
            break; 
        case Type::Suite :
			s += "Suite";
            break;
        default:
            break;   
    }
	s +="\tprix : "; 
    s += std::to_string(chambre.price()); 
    s += " euro(s)\n";
    return s;
 }

std::ostream& operator<<(std::ostream& os, const Chambre& chambre) {
	std::string to_display;
	to_display = display_Chambre(chambre);
	os << to_display << std::endl;
	return os;
}

int rechercheChambre(Type type, int nights, Date date, std::vector<Chambre> chambres, std::vector<Reservation> reservations){
    bool libre= false;
    std::vector<Chambre> chambres_du_bon_type;
    std::vector<Reservation> bonne_reservations;
    int numchambre_libre;
    int prix_chambre;

    //on récupère les chambres qui nous interesses
    for(auto it1 = chambres.begin(); it1 != chambres.end(); it1++){ 
        if(type == it1->type()){
            chambres_du_bon_type.emplace_back(*it1);
        }
    }

    //parmis les chambres du bon type, on regarde s'ils y en à qui sont réserver et on recupères ces réservations
    for(auto it1 = chambres_du_bon_type.begin(); it1 != chambres_du_bon_type.end(); it1++){ 
        for(auto i=0; i<reservations.size(); i++){
            if(it1->num() == reservations.at(i).getnumchambre()){
               bonne_reservations.emplace_back(reservations.at(i));
            }
        }        
    }

    //on regarde si la date des réservations coïncide avec la date entrée
    for(auto it1 = chambres_du_bon_type.begin(); it1 != chambres_du_bon_type.end(); it1++){
        for(auto i=0; i<bonne_reservations.size(); i++){
            if(it1->num() == bonne_reservations.at(i).getnumchambre()){
                if(date > (bonne_reservations.at(i).getbegin() + bonne_reservations.at(i).getnights())){
                    libre = true;
                    numchambre_libre = it1->num();
                    prix_chambre = it1->price();
                }
                else if((date + nights) < (bonne_reservations.at(i).getbegin())){
                    libre = true;
                    numchambre_libre = it1->num();
                    prix_chambre = it1->price();
                }
                else{
                    libre=false;
                }
            }
        }
    }

    if(libre==true){
        std::cout<< "la chambre n° " << std::to_string(numchambre_libre) << " est disponible" << std::endl;
        std::cout<< "prix par nuit : " << std::to_string(prix_chambre) << "€" << std::endl;
        std::cout<< "prix au total : " << std::to_string(prix_chambre*nights) << "€" << std::endl;
        return numchambre_libre;
    }else{
        std::cout<< "aucune chambre trouvée" << std::endl;
        return -1;
    }
}
