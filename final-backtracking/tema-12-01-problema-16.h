#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Pe fiecare din cele n scaune dintr-o
// incapere, asezate unul langa altul pe un
// rand, se gaseste un copil. Intre oricare doi
// copii cu scaunele vecine se insca neintelegeri.
// Sa se reaseze copiii pe scaune astfel incat fostii
// vecini sa fie despartiti de cel putin doi
// copii.

int n;
int s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

// ???????????????????????????????

bool areVecin(int i, int k) {
	for (int v = -2; i + v < i + 3; v++) {
		if (i + v > -1 && i + v < k + 1) {
			if (s[i - v] == s[i] - 1 || s[i - v] == s[i] + 1 && s[i - v] != 0) {
				return 1;
			}
		}
	}
	return 0;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[i] == s[k]) {
			return 0;
		}
		if (areVecin(i, k)) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k) {
	if (k == n - 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < n; i++) {
		s[k] = i + 1;
		if (valid(k)) {
			if (solutie(k)) {
				tipar();
			}
			else {
				back(k + 1);
			}
		}
	}
}

void rezolvare() {
	cout << "Introduceti n : ";
	cin >> n;

	back(0);
}