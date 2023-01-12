#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Sa se genereze produsul cartezian a n multimi
// A1,A2,...,An cu Ai={1,2...ai}

int n;
int a[100], x[100][100];
int s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
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
	for (int i = 0; i < a[k]; i++) {
		s[k] = x[k][i];
		if (solutie(k)) {
			tipar();
		}
		else {
			back(k + 1);
		}
	}
}

void citire() {
	cout << "Introduceti n : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti a[" << i << "] : ";
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++) {
			x[i][j] = j + 1;
		}
	}
}

void rezolvare() {
	citire();
	back(0);
}