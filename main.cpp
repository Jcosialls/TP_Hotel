#include <iostream>
#include "client.h"
#include "chambre.h"

int main(){
    Client client1("JB", "Joshua", "De_Belfort");
    display_Client(client1);

    Chambre chambre1(1,Type::Single,15);
    display_Chambre(chambre1);
	chambre1.setprice(20);
	display_Chambre(chambre1);
	std::vector<Chambre> chambres = { chambre1 };

	Hotel Ibis("IBISHOTEL01", "Ibis Hotel", "Dijon", chambres);
	display_Hotel(Ibis);

    return 0;
}
