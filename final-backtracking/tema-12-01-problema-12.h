#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Sa se genereze toate numerele naturale de n cifre
// care sunt supermultiple de k adica numarul si respectiv
// toate numerele ce se obtin din el prin eliminarea
// cifrelor sale incepand cu cifra unitatilor sunt multiple
// de k.

int n, m;
int s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i];
	}
	cout << endl;
}

bool valid(int k) {
	int r = 0;
	for (int i = 0; i < k + 1; i++) {
		r = r * 10 + s[i];
	}
	if (r % m == 0) {
		return 1;
	}
	return 0;
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
}

void rezolvare() {
	citire();
	back(0);
}