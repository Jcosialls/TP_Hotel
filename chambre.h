#pragma once 

class Reservation;

#include <iostream>
#include <vector>
#include "date.h"

enum class Type{Single, Double, Suite}; 

class Chambre{
    private: 
        int _num;
        Type _type;
        int _price;
    public:
        Chambre(int num, Type type, int price);
        bool isChambre(int num, int price);  
        int num()const;
        Type type()const;
        int price()const;
		void setprice(int price);
};

//--------------Helper Functions-------------//
Type search_Type();
int search_Chambre(Type type, int nights, Date date, std::vector<Chambre> chambres, std::vector<Reservation> reservations);
std::string display_Chambre(Chambre chambre);

//--------------Overloading Ops-------------//
std::ostream& operator<<(std::ostream& os, const Chambre& chambre);

