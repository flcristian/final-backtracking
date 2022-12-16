#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Sa se genereze toate sirurile de lungime m (1<=m<=10) formate din
// divizori ai unui numar natural x (1<=x<=999), aflati in ordine crescatoare.
// Fiecare sir rezultat va fi scris pe cate o linie in fisierul text sir.out,
// iar numerele de pe linie vor fi despartite prin cate un spatiu.
// In cazul in care nu exista solutie se va scrie mesajul 'Imposibil'.

int x, m, dim, c = 0;
int divizori[1000];
int s[100];
int solutii[100][100];

void atribuire() {
	dim = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			divizori[dim] = i;
			dim++;
		}
	}
}

void tiparSiAdaugare() {
	for (int i = 0; i < m; i++) {
		solutii[c][i] = s[i];
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
	if (k == m - 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < dim; i++) {
		s[k] = divizori[i];
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
	ofstream f("problema1-out.txt");
	if (c == 0) {
		f << "Imposibil" << endl;
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < m; j++) {
			f << solutii[i][j];
			if (j != m - 1) {
				f << " ";
			}
		}
		if (i != c - 1) {
			f << endl;
		}
	}
	f.close();
}

void rezolvare() {
	cout << "Introduceti m : ";
	cin >> m;
	cout << "Introduceti x : ";
	cin >> x;
	atribuire();

	back(0);
	output();
}
