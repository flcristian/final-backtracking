#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Sa se scrie un program care afiseaza toate numerele
// de n cifre egale cu de k ori produsul cifrelor.

int n, m;
int s[100];

void tipar(int k) {
	int r = 0, p = 1;
	for (int i = 0; i <= k; i++) {
		p *= s[i];
		r = r * 10 + s[i];
	}
	if (r == p * m) {
		for (int i = 0; i < n; i++) {
			cout << s[i];
		}
		cout << endl;
	}
}

bool solutie(int k) {
	if (k == n - 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < 10; i++) {
		if (i == 0 && k == 0) {
			i++;
		}

		s[k] = i;

		if (solutie(k)) {
			tipar(k);
		}
		else {
			back(k + 1);
		}
	}
}

void citire() {
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti m : ";
	cin >> m;
}

void rezolvare() {
	citire();
	back(0);
}
