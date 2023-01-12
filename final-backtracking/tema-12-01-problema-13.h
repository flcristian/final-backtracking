#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Sa se afiseze toate numerele naturale de n cifre
// care contin m cifre de 1.

int n, m;
int s[100];

void tipar(int k) {
	int f[10]{};
	for (int i = 0; i < k + 1; i++) {
		f[s[i]]++;
	}
	if (f[1] == m) {
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