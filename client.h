#pragma once
#include <iostream>
#include <vector>

class Client{
    public:
        Client(std::string id, std::string firstname, std::string lastname);
        std::string id()const;
        std::string firstname()const;
        std::string lastname()const; 
        void setid(std::string id);
    private:
        std::string _id;
        std::string _firstname;
        std::string _lastname;

}; 
//--------------Helper Functions-------------//
std::string enter_Client(std::vector<Client>& clients);
std::string display_Client(Client client);

//--------------Overloading Ops-------------//
std::ostream& operator<<(std::ostream& os, Client client);

