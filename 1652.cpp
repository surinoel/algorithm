#include <string>
#include <iostream>

using namespace std;

int mat[100][100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '.') mat[i][j] = 0;
			else mat[i][j] = 1;
		}
	}

	int row, col;
	row = col = 0;
	for (int i = 0; i < n; i++) {
		bool ok = false;
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 1) {
				if (!ok && j - 2 >= 0 && mat[i][j - 2] == 0 && mat[i][j - 1] == 0) {
					row += 1; 
				}
				if (j + 2 < n && mat[i][j + 1] == 0 && mat[i][j + 2] == 0) {
					row += 1;
				}
				ok = true;
			}
		}
		if (!ok) row += 1;
	}
	
	for (int j = 0; j < n; j++) {
		bool ok = false;
		for (int i = 0; i < n; i++) {
			if (mat[i][j] == 1) {
				if (!ok && i - 2 >= 0 && mat[i - 2][j] == 0 && mat[i - 1][j] == 0) {
					col += 1;
				}
				if (i + 2 < n && mat[i + 1][j] == 0 && mat[i + 2][j] == 0) {
					col += 1;
				}
				ok = true;
			}
		}
		if (!ok) col += 1;
	}

	if (n == 1) row = col = 0;
	cout << row << ' ' << col << '\n';
	return 0;
}
