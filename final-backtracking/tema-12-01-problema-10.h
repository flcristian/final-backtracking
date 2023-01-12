#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Sa se genereze toate functiile
// surjective f:{1,2...,n} -> {1,2...,n}

int n, m;
int x[100], y[100];
int s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << "f(" << i + 1 << ") = " << s[i] << " ";
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
	int n_m;
	(k == 0 ? n_m = n : n_m = m);
	for (int i = 0; i < n_m; i++) {
		(k == 0 ? s[k] = x[i] : s[k] = y[i]);
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
	cout << "Introduceti m : ";
	cin >> m;
	
	for (int i = 0; i < n; i++) {
		x[i] = i + 1;
	}
	for (int i = 0; i < m; i++) {
		y[i] = i + 1;
	}
}

void rezolvare() {
	citire();
	back(0);
}