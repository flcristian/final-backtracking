#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int k, n, m, x, y, z, t, a[11][11], dr[2][101];

void afis() {
	cout << "aici" << endl;
	for (int i = 0; i < 100; i++) {
		cout << "(" << dr[0][i] << ", " << dr[1][i] << ")";
		if (i != k) {
			cout << " ";
		}
	}
}




void citire() {
	ifstream f("mouse-in.txt");
	f >> n >> m;
	f >> x >> y >> z >> t;
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			if (i == 0 || j == 0 || i == n + 1 || j == m + 1) {
				a[i][j] = 1;
			}
			else {
				f >> a[i][j];
			}
		}
	}
}

void bordare() {
	
	for (int c = 0; c <= n + 1; c++) {

		a[c][0] = 1;
		a[c][m + 1] = 1;
	}

	for (int c = 0; c <= m + 1; c++) {
		a[0][c] = 1;
		a[n + 1][c] = 1;
	}
}



void back(int x ,int y) {

	if (x == z && y == t) {

		afis();
		return;
	}

	cout << "ceva";
	cout << x << " " << y << " " << a[x][y] << endl;
	if (a[x][y] == 0) {
		a[x][y] = 2;
		k++;
		dr[0][k] = x;
		dr[1][k] = y;
		for (int i = 0; i < 4; i++) {
			back(x + dx[i], y + dy[i]);
			a[x][y] = 0;
			k--;
		}
	}

}