#include "Initialize.h"

void attendanceCalc() {
	visitors = actual.getPrestige() * (amenities / 10000) * (prizeMoney/10000) + happiness;
	if (visitors > actual.getCap()) visitors = actual.getCap();
	ticketsales = visitors * ticketprice;
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

void _happiness() {
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
	
	if (_choice.getMod() < 0) cout << "Oh no. It seems people don't like your sponsor. They seem... dissapointed." << endl;
	else cout << "People seem content about your sposor." << endl;
}

void money() {
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
	}

	wallet += money;

	cout << "Total earned today: $" << (int)(ticketsales + money) << endl;
}

void update(){
	static int updateCounter = 0;
	//checks if player hasn't gone bankrupt or happiness <= 20


	cout << "Start of the day balance: $" << wallet << "." << endl << endl;

	attendanceCalc();
	//people
	cout << "Today " << visitors << " people visited the event, making $" << ticketsales << " in tickets." << endl;

	//games


	//rng
	rng();

	//happiness
	_happiness();

	//money making
	money();

} //runs all the logic

int main() {
	string test;
	getline(cin, test); cout << test;
	init();
	intro();
	for (int i = 0; i < duration; i++) {
		update();
	}
	cin >> test;
	return 0;
}