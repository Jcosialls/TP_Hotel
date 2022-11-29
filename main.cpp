#include <iostream>
#include "client.h"
#include "chambre.h"

int main(){
    Client client1("JB", "Joshua", "De_Belfort");
    display_Client(client1);

    Chambre chambre1(1,Type::Single,15);
    display_Chambre(chambre1);

    return 0;
}
