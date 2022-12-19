#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Se citest ce la tastatura numerele naturale n <= 10 si
// m <= 50. Consideram primele m numere primee de cel putin
// doua cifre. Sa se scrie in fisierul prime.out toate
// sirurile de n numere prime dinstincte din cele m,
// fiecare sir scris pe cate o linie.

int m, n, c = 0;
int x[100];
int s[100];
int solutii[1000][1000];

int countDiv(int x) {
	int c = 0;
	for (int i = x; i > 0; i--) {
		if (x % i == 0) {
			c++;
		}
	}
	return c;
}

bool prim(int x) {
	if (countDiv(x) == 2) {
		return 1;
	}
	return 0;
}

void atribuire() {
	for (int i = 0, j = 11; i < m; j++) {
		if (prim(j)) {
			x[i] = j;
			i++;
		}
	}
}

void tiparSiAdaugare() {
	for (int i = 0; i < n; i++) {
		solutii[c][i] = s[i];
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
	for (int i = 0; i < m; i++) {
		s[k] = x[i];
		if (valid(k)) {
			if (solutie(k)) {
				tiparSiAdaugare();
				c++;
			}
			else {
				back(k + 1);
			}
		}
	}
}

void output() {
	ofstream f("problema4-out.txt");
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < n; j++) {
			f << solutii[i][j];
			if (j != n - 1) {
				f << " ";
			}
		}
		if (i != c - 1) {
			f << endl;
		}
	}
}

void rezolvare() {
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti m : ";
	cin >> m;
	atribuire();
	back(0);
	output();
}