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


void display_Chambre(Chambre chambre){
    std::cout<< "Chambre num " << chambre.num()<<"\tType de chambre : ";
    switch(chambre.type()){
        case Type::Single :
            std::cout<< "Chambre simple lit";
            break;
        case Type::Double :
            std::cout<< "Chambre double lit";
            break; 
        case Type::Suite :
            std::cout<< "Suite";
            break;
        default:
            break;   
    }
    std::cout<< "\tprix : "<< chambre.price()<<"euro(s)"<<std::endl;
 }