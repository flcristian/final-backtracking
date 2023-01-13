#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Scrieti un program care afiseaza toate
// modalitatile de a aranja elementele unui
// vector dat de numere intregi, astfel incat in
// sirul rezultat sa nu existe doua elemente
// alaturate negative.

int n;
int x[100], s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[i] == s[k]) {
			return 0;
		}
		if (s[i] < 0 && s[i + 1] < 0) {
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
		s[k] = x[i];
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

void citire() {
	cout << "Introduceti n : ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Introduceti x[" << i << "] : ";
		cin >> x[i];
	}
}

void rezolvare() {
	citire();
	back(0);
}