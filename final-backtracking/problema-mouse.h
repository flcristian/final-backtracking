#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Pozitie {
	int x = -1;
	int y = -1;

	bool isEqual(Pozitie a) {
		if (x != a.x || y != a.y) {
			return 0;
		}
		return 1;
	}
};

struct Path {
	Pozitie pozitii[100];
	int dim;

	bool isEqual(Path path) {
		if (dim != path.dim) {
			return 0;
		}
		for (int i = 0; i < dim; i++) {
			if (!pozitii[i].isEqual(path.pozitii[i])) {
				return 0;
			}
		}
		return 1;
	}
};

int n, m, xm, ym, xb, yb;
int tabla[1000][1000];
int lastPosCount = 0;
Pozitie lastValidPositions[10];
Pozitie s[1000];
Path drumuri[100];

void citire() {
	ifstream f("mouse-in.txt");
	f >> n >> m;
	f >> ym >> xm >> yb >> xb;
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			if (i == 0 || j == 0 || i == n + 1 || j == m + 1) {
				tabla[i][j] = 1;
			}
			else {
				f >> tabla[i][j];
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		switch (i)
		{
		case 0:
			if (tabla[xb - 1][yb] != 0) {
				lastValidPositions[lastPosCount].x = yb;
				lastValidPositions[lastPosCount].y = xb - 1;
				lastPosCount++;
			}
			break;
		case 1:
			if (tabla[xb][yb - 1] != 0) {
				lastValidPositions[lastPosCount].x = yb - 1;
				lastValidPositions[lastPosCount].y = xb;
				lastPosCount++;
			}
			break;
		case 2:
			if (tabla[xb + 1][yb] != 0) {
				lastValidPositions[lastPosCount].x = yb;
				lastValidPositions[lastPosCount].y = xb + 1;
				lastPosCount++;
			}
			break;
		case 3:
			if (tabla[xb][yb + 1] != 0) {
				lastValidPositions[lastPosCount].x = yb + 1;
				lastValidPositions[lastPosCount].y = xb;
				lastPosCount++;
			}
			break;
		default:
			break;
		}
	}
}

bool apareUltimaPozitie(int x, int y) {
	for (int i = 0; i < lastPosCount; i++) {
		if (y == lastValidPositions[i].x && x == lastValidPositions[i].y) {
			return 1;
		}
	}
	return 0;
}

bool maiApare(int k, Path drum) {
	for (int i = 0; i < c; i++) {
		Path drum_i = drumuri[i];
		if (drum_i.isEqual(drum)) {
			return 1;
		}
	}
	return 0;
}

bool aparePozitia(int x, int y, Path drum) {
	for (int i = 0; i < drum.dim; i++) {
		if (y == drum.pozitii[i].x && x == drum.pozitii[i].y) {
			return 1;
		}
	}
	return 0;
}

void afisareDrum() {
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			if (aparePozitia(i, j, drumuri[c])) {
				cout << "X ";
			}
			else {
				cout << tabla[i][j] << " ";
			}
		}
		cout << endl;
	}
}

void adaugare(int k) {
	Path drum;
	drum.dim = k + 1;
	for (int i = 0; i < k + 1; i++) {
		Pozitie pos;
		pos.x = s[i].x;
		pos.y = s[i].y;
		drum.pozitii[i] = pos;
	}
	if (!maiApare(k, drum)) {
		drumuri[c] = drum;
		cout << endl;
		afisareDrum();
		c++;
	}
}

void tipar() {
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < drumuri[i].dim; j++) {
			cout << "(" << drumuri[i].pozitii[j].y << " " << drumuri[i].pozitii[j].x << ")";
			if (j != drumuri[i].dim - 1) {
				cout << "-";
			}
		}
		cout << endl;
	}
}

bool valid(int k, Pozitie pos) {
	for (int i = 0; i < k - 1; i++) {
		if (s[i].x == s[k - 1].x && s[i].y == s[k - 1].y) {
			return 0;
		}
	}
	if (tabla[pos.y][pos.x] == 1) {
		return 0;
	}
	return 1;
}

bool solutie(int k) {
	if (!apareUltimaPozitie(s[k - 1].x, s[k - 1].y)) {
		return 0;
	}
	if (s[k].x == xb && s[k].y == yb) {
		return 1;
	}
	return 0;
}

void back(int k, Pozitie pos) {
	if (solutie(k)) {
		adaugare(k);
	}
	else {
		s[k].x = pos.x;
		s[k].y = pos.y;
		Pozitie pos_next;
		for (int i = 0; i < 4; i++) {
			switch (i)
			{
			case 0:
				pos_next.x = pos.x - 1;
				pos_next.y = pos.y;
				break;
			case 1:
				pos_next.x = pos.x;
				pos_next.y = pos.y - 1;
				break;
			case 2:
				pos_next.x = pos.x + 1;
				pos_next.y = pos.y;
				break;
			case 3:
				pos_next.x = pos.x;
				pos_next.y = pos.y + 1;
				break;
			default:
				break;
			}
			if (valid(k, pos_next)) {
				back(k + 1, pos_next);
			}
		}
	}
}

void rezolvare() {
	citire();
	//for (int i = 0; i < lastPosCount; i++) {
	//	cout << lastValidPositions[i].x << " " << lastValidPositions[i].y << endl;
	//}
	//cout << endl;
	//for (int i = 0; i < n + 2; i++) {
	//	for (int j = 0; j < m + 2; j++) {
	//		if (i == yb && j == xb) {
	//			cout << "B ";
	//		}
	//		else {
	//			cout << tabla[i][j] << " ";
	//		}
	//	}
	//	cout << endl;
	//}
	Pozitie pos_init;
	pos_init.x = xm, pos_init.y = ym;
	back(0, pos_init);
	tipar();
}