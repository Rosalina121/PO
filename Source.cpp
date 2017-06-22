#include "UpdateFunctions.h"



void update(){ //runs all the logic

	static double totalVisitors = 0;
	static int packed = 0;
	string choice;
	int addTech = 0;
	//checks if player hasn't gone bankrupt or happiness <= 20

	cout << "Day - " << updateCounter + 1 << endl;
	cout << "Start of the day balance: $" << (int)wallet << "." << endl << endl;

	attendanceCalc();
	//people
	cout << "Today " << visitors << " people visited the event, making $" << ticketsales << " in tickets." << endl;
	if (visitors >= actual.getCap()) { cout << "Congratulations! The event is so popular we're packed!" << endl << endl; packed++; }
	//games

	totalVisitors += visitors;
	//games
	if (updateCounter >= duration - 4) { //games are only played during last 4 days
		games(gameDay);
	}
	//rng
	rng();

	//happiness
	_happiness(updateCounter);

	//money making
	money();

	if (wallet <= 0) {
		clr();
		cout << "Oh no! You've gone bankrupt. You were unsuccesfull in creating the event." << endl;
		cout << "Better luck next time! Thank's for playing." << endl;
		cout << "Here are some statistics!" << endl;
		cout << "Total visitors: " << totalVisitors << endl;
		cout << "Unique visitors: " << (int)(totalVisitors * 0.87) << endl;
		cout << "End of the game balance: " << (int)wallet << endl;
		cout << "Broken cameras: " << brokenCameras << endl;
		cout << "Broken computers: " << brokenComputers << endl;
		cout << "People's opinion about your sponsor: ";
		if (_choice.getMod() < 0) cout << "negative" << endl;
		else cout << "positive" << endl;
		cout << "People upset because of G2A: ";
		if (toUpper(_choice.getName()) == "G2A") cout << (int)(totalVisitors * 0.87 * 0.2) << endl;
		else cout << " none" << endl;
		cout << "Times the venue was packed: " << packed << endl;
		cout << endl;
		cout << "Final score: " << (int)points(totalVisitors) << endl << endl;
		system("pause");
		exit(0);
	}

	cout << endl;



	cout << "Current balance: $" << (int)wallet << endl;
	if (updateCounter == 0)cin.ignore();
	updateCounter++;
	if (updateCounter != duration) {
		cout << "If you wish you can spend some money you earned on additional technician services.\nWould you like to? (yes/no)" << endl;

		getline(cin, choice);
		choice = toUpper(choice);

		bool tmp = false;
		if (choice == "YES") {
			cout << "How much would you like to spend? ";
			do {
				addTech = checkInput();
				if (addTech > wallet) {
					cout << "You don't have enough money. Type in a lower number." << endl;
				}
				else {
					if (prizeMoney <= 0) {
						cout << "You can't assign a negative number or no money at all. Try again." << endl;
					}
					else {
						technicians += addTech;
						tmp = true;
					}
				}
			} while (tmp == false);
		}


	}
	if (updateCounter != duration) clr();
	if (updateCounter == duration) {
		cout << endl << endl;
		cout << "The last day has come. Here are some statistics!" << endl; //total Visitors and unique visitors, some other stats
		cout << "Total visitors: " << totalVisitors << endl;
		cout << "Unique visitors: " << (int)(totalVisitors * 0.87) << endl;
		cout << "End of the game balance: " << (int)wallet << endl;
		cout << "Broken cameras: " << brokenCameras << endl;
		cout << "Broken computers: " << brokenComputers << endl;
		cout << "People's opinion about your sponsor: ";
		if (_choice.getMod() < 0) cout << "negative" << endl;
		else cout << "positive" << endl;
		cout << "People upset because of G2A: ";
		if(toUpper(_choice.getName())=="G2A") cout << (int)(totalVisitors * 0.87 * 0.2) << endl;
		else cout << " none" << endl;
		cout << "Times the venue was packed: " << packed << endl;
		cout << endl;
		cout << "Final score: " << (int)points(totalVisitors) << endl << endl;
		cout << "Thank you for playing!" << endl;
	}
	
} 

int main() {
	init();
	intro();
	for (int i = 0; i < duration; i++) {
		update();
	}
	system("pause");
	return 0;
}