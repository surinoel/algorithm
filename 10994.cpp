#include <iostream>

using namespace std;

char mat[500][500];

void print(int n, int x, int y) {
	if (n == 1) {
		mat[x][y] = '*';
		return;
	}

	int size = 4 * (n - 1) + 1;
	for (int j = y; j < y + size; j++) {
		mat[x][j] = '*';
		mat[x + size - 1][j] = '*';
	}
	for (int i = x; i < x + size; i++) {
		mat[i][y] = '*';
		mat[i][y + size - 1] = '*';
	}

	print(n - 1, x + 2, y + 2);
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < 4 * (n - 1) + 1; i++) {
		for (int j = 0; j < 4 * (n - 1) + 1; j++) {
			mat[i][j] = ' ';
		}
	}
	
	print(n, 0, 0);

	for (int i = 0; i < 4 * (n - 1) + 1; i++) {
		for (int j = 0; j < 4 * (n - 1) + 1; j++) {
			cout << mat[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	return 0;
}
