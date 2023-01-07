#include <iostream>
#include "client.h"
#include <vector>

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

void Client::setid(std::string id){
    _id = id;
}

//--------------Helper Functions-------------//
std::string enter_Client(std::vector<Client>& clients){
    std::string surname_client;
    std::string id_client;
    std::string name_client;
    bool exist = false;

    std::cout<< "Entrer le nom du client : "<<std::endl;
    std::cin>> surname_client;
    for(auto it = clients.begin(); it != clients.end(); it++){
        if(surname_client == it->lastname()){ //le client existe
            exist = true;
            std::cout<< *it;
            return it->id();
        }else{}                                      //le client n'existe pas                                 
    }
    if(exist == false){  //on crée un client
        std::cout<< "Entrer l'identifient du client "<< std::endl;
        std::cin>> id_client;
        std::cout<< "Entrer le prenom du client "<< std::endl;
        std::cin>> name_client;
        Client new_client(id_client,name_client,surname_client);
        clients.push_back(new_client);
        std::cout<< new_client;
        return id_client;
    }
    
}

std::string display_Client(Client client){
    std::string c = client.firstname() + " " + client.lastname() + " id : " + client.id();
    return c;
}


//--------------Overloading Ops-------------//
std::ostream& operator<<(std::ostream& os, Client client) {
    std::string to_display = display_Client(client);
    os << to_display << std::endl;
    return os;
}

