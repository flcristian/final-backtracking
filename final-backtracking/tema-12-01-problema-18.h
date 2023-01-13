#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Sa se genereze toate matricele
// binare cu n linii si n coloane astfel
// incat fiecare coloana a matricei sa
// contina exact o singura valoare de 0.

int n;
int s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[j] == i) {
				cout << 0 << " ";
			}
			else {
				cout << 1 << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

bool solutie(int k) {
	if (k == n - 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < n; i++) {
		s[k] = i;

		if (solutie(k)) {
			tipar();
		}
		else {
			back(k + 1);
		}
	}

}

void rezolvare() {
	cout << "Introduceti n : ";
	cin >> n;
	back(0);
}