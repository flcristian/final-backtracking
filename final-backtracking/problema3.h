#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Se considera sirul cifrelor de la 0 la 9.
// Sa se genereze toate numerele de n cifre (n <= 9)
// care nu contin trei cifre pare sau trei cifre impare
// alaturate. Fiecare numar rezultat va fi scris pe cate
// o linie in fisierul cifre.out.

int x[10] = { 0,1,2,3,4,5,6,7,8,9 };
int n, c = 0;
int s[100];
int solutii[1000][1000];

void tiparSiAdaugare() {
	for (int i = 0; i < n; i++) {
		solutii[c][i] = s[i];
		cout << s[i];
	}
	cout << endl;
}

bool par(int x) {
	if (x % 2 == 0) {
		return 1;
	}
	return 0;
}

bool valid(int k) {
	int count = 0;
	for (int i = 0; i <= k; i++) {
		if (par(s[i]) == par(s[i + 1])) {
			count++;
		}
		else {
			count = 0;
		}
		if (count == 2) {
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
		if (k == 0 && i == 0) {
			i++;
		}
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
	ofstream f("problema2-out.txt");
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < n; j++) {
			f << solutii[i][j];
		}
		if (i != c - 1) {
			f << endl;
		}
	}
	f.close();
}

void rezolvare() {
	cout << "Introduceti n : ";
	cin >> n;
	
	back(0);
	output();
}