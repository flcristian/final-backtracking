#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Sa se genereze toate permutarile multimii
// {1,2...,n} cu proprietatea ca diferenta
// in modul dintre oricare doua numere consecutive
// este cel putin egala cu o valoare v citita
// de la tastatura.

int n, v;
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
		int dif = s[i] - s[i + 1];
		if (dif < v && (dif * (-1)) < v) {
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
	cout << "Introduceti valoarea : ";
	cin >> v;

	back(0);
}