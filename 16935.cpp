#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, r;
int mat[100][100];
int tmat[100][100];

void go1(void) {
	memcpy(tmat, mat, sizeof(mat));
	for (int i = 0; i < n; i++) {
		memcpy(mat[i], tmat[n - 1 - i], sizeof(mat[i]));
	}
}

void go2(void) {
	memcpy(tmat, mat, sizeof(mat));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat[i][j] = tmat[i][m - 1 - j];
		}
	}
}

void go3(void) {
	int tn = m, tm = n;
	memcpy(tmat, mat, sizeof(mat));
	for (int i = 0; i < tn; i++) {
		for (int j = 0; j < tm; j++) {
			mat[i][j] = tmat[n - 1 - j][i];
		}
	}
	swap(n, m);
}

void go4(void) {
	int tn = m, tm = n;
	memcpy(tmat, mat, sizeof(mat));
	for (int i = 0; i < tn; i++) {
		for (int j = 0; j < tm; j++) {
			mat[i][j] = tmat[j][m - i - 1];
		}
	}
	swap(n, m);
}

void go5(void) {
	memcpy(tmat, mat, sizeof(mat));
	for (int i = 0; i < n / 2; i++) {
		for (int j = m / 2; j < m; j++) {
			mat[i][j] = tmat[i][j - m / 2];
		}
	}

	for (int i = n / 2; i < n; i++) {
		for (int j = m / 2; j < m; j++) {
			mat[i][j] = tmat[i - n / 2][j];
		}
	}

	for (int i = n / 2; i < n; i++) {
		for (int j = 0; j < m / 2; j++) {
			mat[i][j] = tmat[i][j + m / 2];
		}
	}

	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < m / 2; j++) {
			mat[i][j] = tmat[i + n / 2][j];
		}
	}
}

void go6(void) {
	memcpy(tmat, mat, sizeof(mat));
	for (int i = n / 2; i < n; i++) {
		for (int j = 0; j < m / 2; j++) {
			mat[i][j] = tmat[i - n / 2][j];
		}
	}

	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < m / 2; j++) {
			mat[i][j] = tmat[i][j + m / 2];
		}
	}

	for (int i = 0; i < n / 2; i++) {
		for (int j = m / 2; j < m; j++) {
			mat[i][j] = tmat[i + n / 2][j];
		}
	}

	for (int i = n / 2; i < n; i++) {
		for (int j = m / 2; j < m; j++) {
			mat[i][j] = tmat[i][j - m / 2];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	
	while (r--) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) go1();
		else if (cmd == 2) go2();
		else if (cmd == 3) go3();
		else if (cmd == 4) go4();
		else if (cmd == 5) go5();
		else if (cmd == 6) go6();
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
