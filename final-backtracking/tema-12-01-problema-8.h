#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Sa se genereze toate submultimile nevide ale
// multimii A={a1,a2...,an}

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
		cout << "Introduceti a[" << i << "] : ";
		cin >> x[i];
	}
}

void rezolvare() {
	citire();
	for (p = 1; p <= n; p++) {
		back(0);
	}
}