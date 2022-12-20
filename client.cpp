#include <iostream>
#include "client.h"

Client::Client(std::string id, std::string firstname, std::string lastname)
    : _id(id), _firstname(firstname), _lastname(lastname){
    }

std::string Client::id()const{
    return _id;
} 

std::string Client::firstname()const{
    return _firstname;
} 

std::string Client::lastname()const{
    return _lastname;
} 

std::string display_Client(Client client){
    std::string c = "Bonjour" + client.firstname() + " " + client.lastname();
    return c;
}

std::ostream& operator<<(std::ostream& os, Client client) {
    std::string to_display = display_Client(client);
    os << to_display << std::endl;
    return os;
}