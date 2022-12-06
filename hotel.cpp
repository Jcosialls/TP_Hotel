#include <iostream>
#include <vector>
#include "hotel.h"

Hotel::Hotel(std::string id, std::string name, std::string city,
	std::vector<Chambre> chambres) : _id(id), _name(name), _city(city), _chambres(chambres) {

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
void display_Hotel(Hotel hotel) {
	std::cout << hotel.id() << " : " << hotel.name() << " de " << hotel.city() << std::endl;
	for (int i = 0; i < hotel.chambres().size(); i++) {
		display_Chambre(hotel.chambres().at(i));
	}
}