#include "Initialize.h"

void attendanceCalc() {

	visitors = actual.getPrestige() * (amenities / 10000) * (prizeMoney/1000) + happiness;
	if (visitors > actual.getCap()+1759) visitors = actual.getCap()+1759; //1759 - approximate amount of ppl that might still get inside despite the venue cap
	ticketsales = visitors * ticketprice;
}

string random() {
	int rng = rand() % 100;
	if (rng < 50) {
		return "2:0";
	}
	else {
		return "2:1";
	}
}

void rng() {
	int rng = rand() % 100;
	if (technicians < 650000 && rng <= 50) {
		if (rng < 25) {
			cout << "Oh no! One of the computers broke and you had to replace it.\nConsider investing more in technicians.\nThe replacement costs you $";
		}
		else {
			cout << "Oh no! One of the cameras broke and you had to replace it.\nConsider investing more in technicians.\nThe replacement costs you $";
		}
		cout << rng * 1000 << "." << endl;
		wallet -= rng * 1000;
		happiness -= 100;
	}
}

Team teamCompare(Team a, Team b) {
	if (a.getStrenght() == b.getStrenght()) {
		if (a.getFame() > b.getFame()) {
			return a;
		}
		else {
			return b;
		}
	}
	else {
		if (a.getStrenght() > b.getStrenght()) {
			return a;
		}
		else {
			return b;
		}
	}
}

void games(int day) {
	switch (day) {
	case 1:	{
		for (int i = 0; i < 8; i++) {
			dayOne[i] = teamCompare(listOfTeams[2*i],listOfTeams[2*i+1]);
			cout << "Match " << i + 1 << " of the day: " << listOfTeams[2 * i].getName() << " vs. " << listOfTeams[2 * i + 1].getName() << endl;
			cout << "And the winner is: " << dayOne[i].getName() << " with a score of " << random() << endl << endl;
			happiness += 10 * dayOne[i].getFame();
		}
	}
			break;
	case 2: {
		for (int i = 0; i < 4; i++) {
			dayTwo[i] = teamCompare(dayOne[2 * i], dayOne[2 * i + 1]);
			cout << "Match " << i + 1 << " of the day: " << dayOne[2 * i].getName() << " vs. " << dayOne[2 * i + 1].getName() << endl;
			cout << "And the winner is: " << dayTwo[i].getName() << " with a score of " << random() << endl << endl;
			happiness += 10 * dayTwo[i].getFame();
		}
	}
			break;
	case 3: {
		for (int i = 0; i < 2; i++) {
			dayThree[i] = teamCompare(dayTwo[2 * 1], dayTwo[2 * 1 + 1]);
			cout << "Match " << i + 1 << " of the day: " << dayTwo[2 * i].getName() << " vs. " << dayTwo[2 * i + 1].getName() << endl;
			cout << "And the winner is: " << dayThree[i].getName() << " with a score of " << random() << endl << endl;
			happiness += 10 * dayThree[i].getFame();
		}
	}
			break;
	case 4: {
		Team winner = teamCompare(dayThree[0], dayThree[1]);
		cout << "The final match between " << dayThree[0].getName() << " and " << dayThree[1].getName() << endl;
		cout << "And the winner is... " << winner.getName() << endl << endl;
	}
	}
	gameDay++;
}

void _happiness(int updateNo) {
	if (amenities <= 500000) {
		for (int i = 0; i < 2; i++) {
			happiness += scroogeSet[i].getLike() * 23;
		}
		for (int i = 0; i < 2; i++) {
			happiness += instantNoodles[i].getLike() * 13;
		}
	}
	else {
		if (amenities <= 1000000) {
			for (int i = 0; i < 3; i++) {
				happiness += regularSet[i].getLike() * 24;
			}		
			for (int i = 0; i < 3; i++) {
				happiness += caviar[i].getLike() * 12;
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				happiness += generousSet[i].getLike() * 25;
			}
			for (int i = 0; i < 3; i++) {
				happiness += caviar[i].getLike() * 11;
			}
		}
	}
	happiness += _choice.getMod() / 2;
	if (updateNo == 1) {
		if (_choice.getMod() < 0) cout << "Oh no. It seems people don't like your sponsor. They seem... dissapointed." << endl;
		else cout << "People seem content about your sposor." << endl;
	}
}

void money() {
	static int lastHappiness = 0;

	double money = 0;
	if (amenities <= 500000) {
		for (int i = 0; i < 2; i++) {
			money += scroogeSet[i].getCash();
		}
		for (int i = 0; i < 2; i++) {
			money += instantNoodles[i].getCash();
		}
	}
	else {
		if (amenities <= 1000000) {
			for (int i = 0; i < 3; i++) {
				money += regularSet[i].getCash();
			}
			for (int i = 0; i < 3; i++) {
				money += caviar[i].getCash();
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				money += generousSet[i].getCash();
			}
			for (int i = 0; i < 3; i++) {
				money += caviar[i].getCash();
			}
		}

		if (lastHappiness > happiness) {
			wallet += money * (1 - (1 / happiness));
		}
		else {
			wallet += money;
		}

		lastHappiness = happiness;

		cout << "Total earned today: $" << (int)(ticketsales + money) << endl;
	}
}

void update(){ //runs all the logic

	static double totalVisitors = 0;
	string choice;
	int addTech = 0;
	//checks if player hasn't gone bankrupt or happiness <= 20
	if (wallet <= 0) {

	}

	cout << "Start of the day balance: $" << wallet << "." << endl << endl;

	attendanceCalc();
	//people
	cout << "Today " << visitors << " people visited the event, making $" << ticketsales << " in tickets." << endl;
	if (visitors >= actual.getCap()) cout << "Congratulations! The event is so popular we're packed!" << endl;
	//games

	totalVisitors += visitors;
	//games
	if (updateCounter > duration - 4) { //games are only played during last 4 days
		games(gameDay);
	}
	//rng
	rng();

	//happiness
	_happiness(updateCounter);

	//money making
	money();
 
	cout << endl;

	cout << "Current balance: $" << (int)wallet << endl;
	cout << "If you wish you can spend some money you earned on additional technician services.\nWould you like to? (yes/no)" << endl;

	getline(cin, choice);
	choice = toUpper(choice);

	bool tmp = false;
	if (choice == "YES") {
		cout << "How much would you like to spend? ";
		do {
			cin >> addTech;
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

	updateCounter++;



	clr();
	if (updateCounter == duration) {
		cout << "Here are some statistics!" << endl; //total Visitors and unique visitors, some other stats
	}
} 

int main() {
	int a;
	init();
	intro();
	for (int i = 0; i < duration; i++) {
		update();
	}
	cin >> a;
	return 0;
}