#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Sa se genereze toate functiile
// injective f:{1,2...,n} -> {1,2...,m}

int n, m;
int x[100], s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << "f(" << i + 1 << ") = " << s[i] << " ";
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
	for (int i = 0; i < m; i++) {
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
	cout << "Introduceti m : ";
	cin >> m;

	for (int i = 0; i < m; i++) {
		x[i] = i + 1;
	}
}

void rezolvare() {
	citire();
	back(0);
}

