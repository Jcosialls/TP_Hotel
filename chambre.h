#pragma once 
#include <iostream>

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

 void display_Chambre(Chambre chambre);

