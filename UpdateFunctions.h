#include "Initialize.h"

void attendanceCalc() {

	visitors = actual.getPrestige() * (amenities / 10000) * (prizeMoney / 1000) + happiness;
	if (visitors > actual.getCap() + 1759) visitors = actual.getCap() + 1759; //1759 - approximate amount of ppl that might still get inside despite the venue cap
	ticketsales = visitors * ticketprice;
	wallet += ticketsales;
}

string score(Team a, Team b) {
	if (a.getStrenght() > b.getStrenght()) {
		return "2:0";
	}
	else {
		return "2:1";
	}
}

double points(double totalVisits) {
	return happiness + (int)wallet * mode + 10 * _choice.getMod() + totalVisits;
}

void rng() {
	mt19937 _rng(69);
	uniform_int_distribution<int> gen(0, 17);
	int rng = gen(_rng);
	if (technicians < 650000 && rng <= 50) {
		if (rng < 25) {
			cout << "Oh no! One of the computers broke and you had to replace it.\nConsider investing more in technicians.\nThe replacement costs you $";
			brokenComputers++;
		}
		else {
			cout << "Oh no! One of the cameras broke and you had to replace it.\nConsider investing more in technicians.\nThe replacement costs you $";
			brokenCameras++;
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

Team teamCompareLoser(Team a, Team b) {
	if (a.getStrenght() == b.getStrenght()) {
		if (a.getFame() > b.getFame()) {
			return b;
		}
		else {
			return a;
		}
	}
	else {
		if (a.getStrenght() > b.getStrenght()) {
			return b;
		}
		else {
			return a;
		}
	}
}

void games(int day) {
	switch (day) {
	case 1: {
		for (int i = 0; i < 8; i++) {
			dayOne[i] = teamCompare(listOfTeams[2 * i], listOfTeams[2 * i + 1]);
			cout << "Match " << i + 1 << " of the day: " << listOfTeams[2 * i].getName() << " vs. " << listOfTeams[2 * i + 1].getName() << endl;
			cout << "And the winner is: " << dayOne[i].getName() << " with a score of " << score(teamCompare(listOfTeams[2 * i], listOfTeams[2 * i + 1]), teamCompareLoser(listOfTeams[2 * i], listOfTeams[2 * i + 1])) << endl << endl;
			happiness += 10 * dayOne[i].getFame();
		}
	}
			break;
	case 2: {
		for (int i = 0; i < 4; i++) {
			dayTwo[i] = teamCompare(dayOne[2 * i], dayOne[2 * i + 1]);
			cout << "Match " << i + 1 << " of the day: " << dayOne[2 * i].getName() << " vs. " << dayOne[2 * i + 1].getName() << endl;
			cout << "And the winner is: " << dayTwo[i].getName() << " with a score of " << score(teamCompare(dayOne[2 * i], dayOne[2 * i + 1]), teamCompareLoser(dayOne[2 * i], dayOne[2 * i + 1])) << endl << endl;
			happiness += 10 * dayTwo[i].getFame();
		}
	}
			break;
	case 3: {
		for (int i = 0; i < 2; i++) {
			dayThree[i] = teamCompare(dayTwo[2 * i], dayTwo[2 * i + 1]);
			cout << "Match " << i + 1 << " of the day: " << dayTwo[2 * i].getName() << " vs. " << dayTwo[2 * i + 1].getName() << endl;
			cout << "And the winner is: " << dayThree[i].getName() << " with a score of " << score(teamCompare(dayTwo[2 * i], dayTwo[2 * i + 1]), teamCompareLoser(dayTwo[2 * i], dayTwo[2 * i + 1])) << endl << endl;
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
			happiness += scroogeSet[i].getLike() * 3;
		}
		for (int i = 0; i < 2; i++) {
			happiness += instantNoodles[i].getLike() * 2;
		}
	}
	else {
		if (amenities <= 1000000) {
			for (int i = 0; i < 3; i++) {
				happiness += regularSet[i].getLike() * 4;
			}
			for (int i = 0; i < 3; i++) {
				happiness += caviar[i].getLike() * 3;
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				happiness += generousSet[i].getLike() * 5;
			}
			for (int i = 0; i < 3; i++) {
				happiness += caviar[i].getLike() * 4;
			}
		}
	}
	happiness += _choice.getMod() / 2;
	if (updateNo == 0) {
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