#include <iostream>
#include <vector>
#include "hotel.h"

Hotel::Hotel(std::string id, std::string name, std::string city,
			 std::vector<Chambre> chambres) : _id(id), _name(name),
			 								  _city(city), _chambres(chambres) {

}
std::string Hotel::id()const {
	return _id;
}
std::string Hotel::name()const {
	return _name;
}
std::string Hotel::city()const {
	return _city;
}
std::vector<Chambre> Hotel::chambres()const {
	return _chambres;
}

void Hotel::addchambre(Chambre chambre) {
	_chambres.push_back(chambre);
}


// Fonction helper
std::string display_Hotel(Hotel hotel) {
	std::string s = hotel.id() + " : " + hotel.name() + " de " + hotel.city() + "\n";
	for (auto i = 0; i < hotel.chambres().size(); i++) {
		s += display_Chambre(hotel.chambres().at(i));
	}
	return s;
}

std::ostream& operator<<(std::ostream& os, const Hotel& hotel) {
	std::string to_display;
	to_display = display_Hotel(hotel);
	os << to_display << std::endl;
	return os;
}