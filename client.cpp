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

void display_Client(Client client){
    std::cout<< "Boujour " << client.firstname() << client.lastname() << std::endl;
}