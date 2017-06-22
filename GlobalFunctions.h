#include "TeamsAndOthers.h"

void initializeTeams() {
	string name;
	ifstream teamsFile("teams.txt");
	for (int i = 0; i < 16; i++) {
		getline(teamsFile, name);
		listOfTeams[i].setName(name);
	}
}

int checkInput() {
	int a;

	while (!(cin >> a)) {
		cout << "Please type in a number: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return a;
}

void clr() {
	system("cls");
}

string toUpper(string a) { //changes all letters in a string to uppercase for case insensitive inputs
	transform(a.begin(), a.end(), a.begin(), ::toupper);
	return a;
}