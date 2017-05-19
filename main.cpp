#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

double wallet;
double happiness;
int duration = 8;

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
	string getName() { return name; }
}actual(" "," ",0,0,0);

class Team {
	string name;
	int fame, strenght; //both randomly generated, fame 0-9, str 0-99
public:
	Team(string nam) {
		srand(time(NULL)); //seed
		name = nam;
		fame = rand() % 10;
		strenght = rand() % 100;
	}
	//TeamCompare() method to compare two teams and determine the winner
};

class Store {
	string name;
	bool isGamer; //Gaming booths attract more people to the event. Adds multiplier to the cash output
	double cashOutput; //Basically a cashOutput * people = money earned
	int likeable; //0-3, the higher the number the more people will come there, the lower the less amused the people are - think G2A
public:
	Store(string nam, bool isG, double cas, int lik) {
		name = nam;
		isGamer = isG;
		cashOutput = cas;
		likeable = lik;
	}
	void Update() {

	}
};

class FoodTruck :Store {

};

void init() {
	int choice;
	string theIf = "yes", inIf;
	cout << "Choose mode:" << endl << "1. Easy | 2. Normal | 3. Hard" << endl;
	cin >> choice;

	switch (choice) { //add foolproof implementaion
	case 1:
		wallet = 10000000;
		happiness = 1000;
		cout << "You choose easy mode." << endl; //check grammar
		break;
	case 2:
		wallet = 6000000;
		happiness = 500;
		cout << "You choose normal mode." << endl;
		break;
	case 3:
		wallet = 3500000;
		happiness = 100;
		cout << "You choose hard mode." << endl;
		break;
	default:
		wallet = 6000000;
		happiness = 500;
		cout << "Deafulted to normal mode." << endl;
		break;
	}
	
	cout << "The simulation lasts 6 in-game days. Would you like to change the duration? (yes/no)" << endl; //foolproof this one too
	cin >> inIf;
	if (inIf == theIf) { //foolproofing needed
		cout << "Specify the duration (no. days): ";
		cin >> duration;
	}
  }

void intro() {
	Venue Spodek("Katowice", "Spodek", 1000000, 11500, 1), Hala("Wroclaw", "Hala Stulecia", 1200000, 10000, 2), Wembley("London", "Wembley", 3000000, 65000, 4), Seoul("Seoul", "Seould WCS", 2750000, 64000, 3);
	int tmp = 0;
	string choice;

	cout << "You have $" << wallet << " in your wallet." << endl;
	cout << "Start by choosing on of the fllowing venues: " << endl;

	Spodek.showVenue();
	Hala.showVenue();
	Wembley.showVenue();
	Seoul.showVenue();

	cout << "Type the full name of the desired venue: "; //make it less sensitive, like check just some of the name or sth.
	cin >> choice;
	do {
		if (choice == "Spodek") {
			actual = Spodek; tmp++;
		}
		else {
			if (choice == "Hala Stulecia") {
				actual = Hala; tmp++;
			}
			else {
				if (choice == "Wembley") {
					actual = Wembley; tmp++;
				}
				else {
					if (choice == "Seoul WCS") {
						actual = Seoul; tmp++;
					}
				}
			}
		}
	} while (tmp == 0);
	cout << "You've chosen: " << actual.getName << endl;
	cout << "Current balance: " << wallet << endl;

	cout << "Now it's time to spend some more money.";
}
 
int main() {

	return 0;
}//4 5 2 3,5 4 4 3 4 oceny