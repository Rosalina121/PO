#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <random>
#include <sstream>

using namespace std;

double wallet;
double happiness;
double technicians = 0, prizeMoney = 0, amenities = 0; //spendings
double settech, setprize, setamenity; //remembers value set by user, used in the update function
int duration = 8;
double visitors;
double ticketprice;

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
		cout << "Capacity: " << capacity << endl;
		cout << "Price:    " << price << endl;
	}
	double getPrice() { return price; }
	string getName() { return name; }
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
}G2A("G2A",1000000,-200),Intel("Intel",700000,100),Coke("Coca Cola",500000,140),Nvidia("Nvidia",600000,120),God("Lord Christ Himself",2000000,1000);//last one is a placeholder and only for test purposes

class Team {
	static int teamCount;
	string name;
	int fame, strenght; //both randomly generated, fame 0-9, str 0-99
public:
	Team(string nam) {
		srand(time(NULL)); //seed
		name = nam;
		fame = rand() % 10;
		strenght = rand() % 100;
	}
	Team() {
		name = " ";
		fame = 0;
		strenght = 0;
	}
	string getName() { return name; }
	int getFame() { return fame; }
	//TeamCompare() method to compare two teams and determine the winner
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
			return visitors * 0.1 * likeable * cashOutput * 2;
		}
		else {
			return visitors * 0.1 * likeable * cashOutput;
		}
	}
};

class FoodTruck :Booth {
public:
	FoodTruck(string nam, double cas, double lik){
		name = nam;
		cashOutput = cas;
		likeable = lik;
	}
};


