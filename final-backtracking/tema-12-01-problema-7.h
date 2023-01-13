#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Sa se genereze toate combinarile de p elemente
// ale multimii {1,2,3...,n}

int n, p;
int x[100], s[100];

void tipar() {
	for (int i = 0; i < p; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[i] >= s[i + 1]) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k) {
	if (k == p - 1) {
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
	cout << "Introduceti p : ";
	cin >> p;

	back(0);
}