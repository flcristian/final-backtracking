#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Sa se genereze toate permutarile multimii
// {a1,a2,a3...,an} citite de la tastatura.

int x[100];
int n;
int s[100];

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
	cout << endl;
}

void rezolvare() {
	citire();
	back(0);
}