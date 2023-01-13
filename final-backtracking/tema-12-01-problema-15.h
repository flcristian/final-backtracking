#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Fie M o multime de numere naturale strict
// pozitive si un numar natural nenul S.
// Sa se afiseze toate submultimile lui M cu
// proprietatea ca suma valorilor elementelor
// submultimii este egala cu S.

int n;
int M[100], S;
int s[100];

void tipar(int k) {
	cout << "(";
	for (int i = 0; i < k + 1; i++) {
		cout << s[i];
		if (i != k) {
			cout << ", ";
		}
	}
	cout << ")" << endl;
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
	int suma = 0;
	for (int i = 0; i < k + 1; i++) {
		suma += s[i];
	}
	if (suma == S) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < n; i++) {
		s[k] = M[i];
		if (valid(k)) {
			if (solutie(k)) {
				tipar(k);
			}
			else {
				back(k + 1);
			}
		}
	}
}

void citire() {
	cout << "Introduceti numarul elementelor : ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Introduceti M[" << i << "] : ";
		cin >> M[i];
	}

	cout << "Introduceti S : ";
	cin >> S;
}

void rezolvare() {
	citire();
	for (int k = 0; k < n; k++) {
		back(k);
	}
}