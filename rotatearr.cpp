#include <iostream>
#include <cstring>

using namespace std;

int mat[100][100];

int n;
void rotate(void) {
	int tmat[100][100];
	memcpy(tmat, mat, sizeof(mat));

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			mat[j][i] = tmat[i][n - j - 1];
		}
	}
}

void printarr(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = n*i + j;
		}
	}
	
	for (int i = 0; i < 5; i++) {
		printarr();
		cout << '\n';
		rotate();
	}
	return 0;
}