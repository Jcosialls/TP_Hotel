#include <iostream>
#include <cassert>
#include "chambre.h"

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