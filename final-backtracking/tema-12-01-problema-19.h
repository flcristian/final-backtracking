#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Sa se calculeze suma tuturor
// numerelor formate numai din
// cifre impare distincte.

int x[5] = { 1,3,5,7,9 }, m;
int suma = 0;
int s[100];

void addSuma(int k) {
	int r = 0;
	for (int i = 0; i < k + 1; i++) {
		r = r * 10 + s[i];
	}
	suma += r;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[i] == s[k]) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k) {
	if (k == m) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < 5; i++) {
		s[k] = x[i];
		if (valid(k)) {
			if (solutie(k)) {
				addSuma(k);
			}
			else {
				back(k + 1);
			}
		}
	}
}

void rezolvare() {
	for (m = 0; m < 5; m++) {
		back(0);
	}
	cout << "Suma este : " << suma << endl;
}