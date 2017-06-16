#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <random>
#include <sstream>
#include <algorithm>


using namespace std;

double wallet = 0;
double happiness = 0;
double technicians = 0, prizeMoney = 0, amenities = 0; //spendings
double settech = 0; //remembers value set by user, used in the update function
int duration = 4, updateCounter = 1, gameDay = 1;
double visitors = 0;
double ticketprice = 0, ticketsales = 0;

class Venue {
	string location, name;
	double price;
	double capacity;
	int prestige; //from 1 to 4, 4 is best
public:
	Venue(string loc, string nam, double pri, double cap, int pre) {
		location = loc;
		name = nam;
		price = pri;
		capacity = cap;
		prestige = pre;
	}
	void showVenue() {
		cout << "Name:     " << name << endl;
		cout << "Location: " << location << endl;
		cout << "Prestige: " << prestige << endl;
		cout << "Capacity: " << (int)capacity << endl;
		cout << "Price:   $" << (int)price << endl;
	}
	double getPrice() { return price; }
	string getName() { return name; }
	int getPrestige() { return prestige; }
	double getCap() { return capacity; }
}actual(" ", " ", 0, 0, 0);

class Sponsor {
	string name;
	double moneyOffer;
	double happinessModifier;
public:
	Sponsor(string nam, double mon, double hap) { 
		name = nam;
		moneyOffer = mon;
		happinessModifier = hap;
	}
	double getOffer() { return moneyOffer; }
	string getName() { return name; }
	double getMod() { return happinessModifier; }
}_choice("",0,0),G2A("G2A",1000000,-200),Intel("Intel",700000,100),Coke("CocaCola",500000,140),Nvidia("Nvidia",600000,120),God("Lord Christ Himself",2000000,1000);//last one is a placeholder and only for test purposes

class Team {
	static int teamCount;
	string name;
	int fame, strenght; //both randomly generated, fame 0-9, str 0-99
public:
	Team(string nam) {
		srand(time(NULL)); //seed
		name = nam;
		fame = rand() % 9;
		strenght = rand() % 101;
	}
	Team() {
		name = " ";
		fame = 0;
		strenght = 0;
	}
	string getName() { return name; }
	int getFame() { return fame; }
	int getStrenght() { return strenght; }
};

class Booth {
protected:
	string name;
	bool isGamer; //Gaming booths attract more people to the event. Adds multiplier to the cash output
	double cashOutput; //Basically a cashOutput * people = money earned
	double likeable; //0.1-3, the higher the number the more people will come there, the lower the less amused the people are - think G2A
public:
	Booth(string nam, bool isG, double cas, double lik) {
		name = nam;
		isGamer = isG;
		cashOutput = cas;
		likeable = lik;
	}
	Booth(){}
	string getName() { return name; }
	double getCash() {
		if (isGamer == true) {
			return visitors * 0.3 * likeable * cashOutput;
		}
		else {
			return visitors * 0.1 * likeable * cashOutput;
		}
	}
	double getLike() { return likeable; }
};

class FoodTruck : public Booth {
public:
	FoodTruck(string nam, double cas, double lik){
		name = nam;
		cashOutput = cas;
		likeable = lik;
	}
};


