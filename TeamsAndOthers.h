#include "Classes.h"

//Venues
Venue Spodek("Katowice", "Spodek", 1000000, 11500, 1), Hala("Wroclaw", "Hala Stulecia", 1200000, 10000, 2), Wembley("London", "Wembley", 3000000, 65000, 4), Seoul("Seoul", "Seould WCS", 2750000, 64000, 3);
Venue listOfVenues[4] = { Spodek, Hala, Wembley, Seoul };
//Teams

Team listOfTeams[16];


Team dayOne[8], dayTwo[4], dayThree[2];
//Booths
Booth genericMerch("Generic Merch (TM)", true, 10, 2), goodMerch("Good Merch (TM)",true,12,2.2), Redbull("Redbull", false, 8, 1.7), Hyperx("HyperX", true, 12, 0.9), NFS("Need For Seat", true, 3, 2.1), Corsair("Corsair", true, 10, 1.3);
//Sponsor specific booths
Booth _Intel("Intel", true, 3, 3), _G2A("G2A", true, 6, 0.1), _Coke("Coca Cola", false, 6, 1), _Nvidia("Nvidia", true, 7, 1);
//Foodtrucks
FoodTruck Pasibus("Pasibus", 5, 2), Panczo("Panczo", 3, 1.5), Langosz("Langosz", 4, 1), KFC("KFC", 7, 2), Ice("Italiano Gelato", 6, 1.7);

//Booth and FTs sets (determined by the amenities initial value)

Booth generousSet[4] = { goodMerch, Hyperx, Corsair, Redbull };
Booth regularSet[3] = { genericMerch, NFS, Redbull };
Booth scroogeSet[2] = { genericMerch, NFS };

FoodTruck caviar[3] = { Pasibus,KFC,Ice };
FoodTruck instantNoodles[2] = { Panczo,Langosz };

void printAmeinites(Booth *booths,int n) {
	for (int i = 0; i < n; i++) {
		cout << booths[i].getName() << endl;
	}
}

void printFoodtrucks(FoodTruck *trucks, int n) {
	for (int i = 0; i < n; i++) {
		cout << trucks[i].getName() << endl;
	}
}