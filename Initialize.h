#include "TeamsAndOthers.h"

void clr() {
	system("cls");
}

string toUpper(string a) { //changes all letters in a string to uppercase for case insensitive inputs
	transform(a.begin(), a.end(), a.begin(), ::toupper);
	return a;
}

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
		wallet = 2000000;
		happiness = 500;
		cout << "Deafulted to normal mode." << endl;
		break;
	}

	cout << "The simulation lasts 4 in-game days (two weekends). Would you like to change the duration? (yes/no)" << endl; //foolproof this one too
	cin >> inIf;
	if (inIf == theIf) { //foolproofing needed
		cout << "Specify the duration (no. days, max 10): ";
		cin >> duration;
	}
	clr();
}

bool venueChoice(Venue theVenue) { //fix the inf loop
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
	srand(time(NULL));
	int a, b;
	a = rand() % 4;
	do {
		b = rand() % 4;
	} while (b == a);

	Sponsor sponsorList[5] = { G2A,Intel,Coke,Nvidia,God };
	
	bool tmp = false;
	bool isLower = false;
	string choice, temp1, temp2, temp3;

	cout << "You have $" << (int)wallet << " in your wallet." << endl;
	cout << "Start by choosing on of the fllowing venues: " << endl;

	Spodek.showVenue();
	cout << endl;
	Hala.showVenue();
	cout << endl;
	Wembley.showVenue();
	cout << endl;
	Seoul.showVenue();
	cout << endl;

	cin.ignore();
	cout << "Type the full name of the desired venue: " << endl; //make it less sensitive, like check just some of the name or sth.
	getline(cin,choice);
	choice = toUpper(choice);

	do {
		if (choice == "SPODEK") {
			tmp = venueChoice(Spodek);
		}
		else {
			if (choice == "HALA STULECIA") {
				tmp = venueChoice(Hala);
			}
			else {
				if (choice == "WEMBLEY") {
					tmp = venueChoice(Wembley);
				}
				else {
					if (choice == "SEOUL WCS") {
						tmp = venueChoice(Seoul);
					}
					else {
						cout << "Please type in a name of correct venue." << endl << endl;
						getline(cin, choice);
						choice = toUpper(choice);
					}
				}
			}
		}
	} while (tmp == false);

	clr();

	cout << "You've chosen: " << actual.getName() << " for the price of " << (int)actual.getPrice() << endl;
	cout << "Current balance: $" << (int)wallet << endl << endl;
	cout << "Woah, what a surprise! Someone wants to sponsor your event.\nYou can choose which sponsor you'd like to collaborate with." << endl << endl;

	cout << sponsorList[a].getName() << " offers you $" << (int)sponsorList[a].getOffer() << " for a exclusive sponsoring deal." << endl;
	cout << sponsorList[b].getName() << " made an offer for $" << (int)sponsorList[b].getOffer() << " for being the main patron of the event." << endl;
	cout << "Which one do you choose? " << endl;

	temp1 = sponsorList[a].getName();
	temp2 = sponsorList[b].getName();

	temp1 = toUpper(temp1);
	temp2 = toUpper(temp2);

	do {
		getline(cin, choice);
		choice = toUpper(choice);
		if (choice == temp1) {
			wallet += sponsorList[a].getOffer();
		}
		else {
			if (choice == temp2) {
				wallet += sponsorList[b].getOffer();
			}
			else {
				cout << "Type in the name of one of the two sponsors you'd like to work with." << endl;
			}
		}
	} while (choice != temp1 && choice != temp2);
	cout << endl;
	clr();

	cout << "With the help of your new sponsor now you have " << (int)wallet << "$ to spend on other things." << endl;
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
	} while (technicians <= 0 || isLower == false);
	isLower = false; settech = technicians;

	cout << "Current balance: $" << (int)wallet << endl;
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
	} while (prizeMoney <= 0 || isLower == false);
	isLower = false;

	cout << "Current balance: $" << (int)wallet << endl;
	cout << "Great! Now it's time for amenities. Tip: The more you spend here the more happy the people will be. ";
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
	} while (amenities <= 0 || isLower == false);
	clr();

	cout << "Current balance: $" << (int)wallet << endl;
	cout << "Awesome. You're all set. These are the teams that confirmed their appereance on your event: " << endl << endl;

	for (int i = 0; i < 12; i++) {
		cout << toUpper(listOfTeams[i].getName()) << endl;
	}
	cout << endl;

	cout << "And also here are the booths that will be present at the venue: " << endl;

	if (amenities <= 500000) {
		printAmeinites(scroogeSet, 2);
		printFoodtrucks(instantNoodles, 2);
	}
	else {
		if (amenities <= 1000000) {
			printAmeinites(regularSet, 3);
			printFoodtrucks(caviar, 3);
		}
		else {
			printAmeinites(generousSet, 4);
			printFoodtrucks(caviar, 2);
		}
	}

	for (int i = 0; i < 4; i++) {
		if (choice == sponsorList[i].getName()) { 
			cout << choice << " (your sponsor)" << endl << endl;
			_choice = sponsorList[i];
		}
	}


	cout << "And last but not least, the price of the tickets. You may type in 0 to make the event admission free." << endl;
	cin >> ticketprice;

	cout << "Alright! Let's start, shall we?" << endl;
}
