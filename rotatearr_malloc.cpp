#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int **mat;
int n;

void rotate(void) {
	int **tmat;
	tmat = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
		tmat[i] = (int*)malloc(sizeof(int)*n);
	}
	memcpy(tmat, mat, sizeof(mat)*n);

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
	mat = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
		mat[i] = (int*)malloc(sizeof(int)*n);
	}

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