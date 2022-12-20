#pragma once
#include <iostream>
#include <vector>
#include "chambre.h"

class Hotel{
	private:
		std::string _id;
		std::string _name;
		std::string _city;
		std::vector<Chambre> _chambres;

	public:
		Hotel(std::string id, std::string name, std::string city,
			  std::vector<Chambre> chambres);
		std::string id()const;
		std::string name()const;
		std::string city()const;
		std::vector<Chambre> chambres()const;
		void addchambre(Chambre chambre);

};

//fonctions helper
std::string display_Hotel(Hotel hotel);
std::ostream& operator<<(std::ostream& os, const Hotel& hotel);