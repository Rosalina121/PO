#include "TeamsAndOthers.h"

void init() {
	int choice;
	string theIf = "yes", inIf;
	cout << "Choose mode:" << endl << "1. Easy | 2. Normal | 3. Hard" << endl;
	cin >> choice;

	switch (choice) { //add foolproof implementaion
	case 1:
		wallet = 4000000;
		happiness = 1000;
		cout << "You choose easy mode." << endl; //check grammar
		break;
	case 2:
		wallet = 2000000;
		happiness = 500;
		cout << "You choose normal mode." << endl;
		break;
	case 3:
		wallet = 1300000;
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

bool venueChoice(Venue theVenue) {
	if (theVenue.getPrice() > wallet) {
		cout << "You don't have enough money. Choose another venue." << endl;
		return false;
	}
	else {
		wallet -= theVenue.getPrice();
		actual = theVenue;
		return true;
	}
}

void intro() {
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, 4);
	int a, b;
	a = distribution(generator);
	do {
		b = distribution(generator);
	} while (b == a);

	Sponsor sponsorList[5] = { G2A,Intel,Coke,Nvidia,God };
	
	bool tmp = false;
	bool isLower = false;
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
			tmp = venueChoice(Spodek);
		}
		else {
			if (choice == "Hala Stulecia") {
				tmp = venueChoice(Hala);
			}
			else {
				if (choice == "Wembley") {
					tmp = venueChoice(Wembley);
				}
				else {
					if (choice == "Seoul WCS") {
						tmp = venueChoice(Seoul);
					}
				}
			}
		}
	} while (tmp == false);

	cout << "You've chosen: " << actual.getName << " for the price of " << actual.getPrice << endl;
	cout << "Current balance: " << wallet << endl;
	cout << "Woah, what a surprise! Someone wants to sponsor your event.\nYou can choose which sponsor you'd like to collaborate with." << endl;

	cout << sponsorList[a].getName << " offers you " << sponsorList[a].getOffer << "$ for a exclusive sponsoring deal." << endl;
	cout << sponsorList[b].getName << " made an offer for " << sponsorList[b].getOffer << "$ for being the main patron of the event." << endl;
	cout << "Which one do you choose? ";
	do {
		cin >> choice;
		if (choice == sponsorList[a].getName) {
			wallet += sponsorList[a].getOffer;
		}
		else {
			if (choice == sponsorList[b].getName) {
				wallet += sponsorList[b].getOffer;
			}
			else {
				cout << "Type in the name of the on of two sponsord you'd like to work with." << endl;
			}
		}
	} while (choice != sponsorList[a].getName || choice != sponsorList[b].getName);

	cout << "With the help of your new sponsor now you have " << wallet << "$ to spend on other things." << endl;
	cout << "Let's start with technicians. Tip: The more you invest the less the equipment will be prone to break." << endl;
	cout << "So... How much do you invest in the technicians? ";
	do {

		cin >> technicians;																							//check or add a check to see if any of the tech, prize and amenit = 0
		if (technicians > wallet) {
			cout << "You don't have enough money. Type in a lower number." << endl;
		}
		else {
			if (technicians <= 0) {
				cout << "You can't assign a negative number or no money at all. Try again." << endl;
			}
			else {
				isLower = true;
				wallet -= technicians;
			}
		}
	} while (technicians <= 0 && isLower == false);
	isLower = false;

	cout << "Awesome! Now actually the most important thing. How much should we spend on the prizes? ";
	do {

		cin >> prizeMoney;
		if (prizeMoney > wallet) {
			cout << "You don't have enough money. Type in a lower number." << endl;
		}
		else {
			if (prizeMoney <= 0) {
				cout << "You can't assign a negative number or no money at all. Try again." << endl;
			}
			else {
				isLower = true;
				wallet -= prizeMoney;
			}
		}
	} while (prizeMoney <= 0 && isLower == false);
	isLower = false;

	cout << "Great! Now it's time for amenities. Tip: The mor you spend here the more happy the people will be. ";
	do {

		cin >> amenities;
		if (amenities > wallet) {
			cout << "You don't have enough money. Type in a lower number." << endl;
		}
		else {
			if (amenities <= 0) {
				cout << "You can't assign a negative number or no money at all. Try again." << endl;
			}
			else {
				isLower = true;
				wallet -= amenities;
			}
		}
	} while (amenities <= 0 && isLower == false);

	cout << "Awesome. You're all set. These are the teams that confirmed their appereance on your event: " << endl;

	for (int i = 0; i < 12; i++) {
		cout << listOfTeams[i].getName << endl;
	}

	cout << "And also here are the booths that will be present at the venue: ";

	if (setamenity <= 500000) {
		printAmeinites(scroogeSet, 2);
		printFoodtrucks(instantNoodles, 2);
	}
	else {
		if (setamenity <= 1000000) {
			printAmeinites(regularSet, 3);
			printFoodtrucks(caviar, 3);
		}
		else {
			printAmeinites(generousSet, 4);
			printFoodtrucks(caviar, 2);
		}
	}


	cout << "And last but not least, the price of the tickets. You may type in 0 to make the event admission free." << endl;
	cin >> ticketprice;

	cout << "Alright! Let's start, shall we?" << endl;
}