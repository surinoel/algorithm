#include <iostream>
#include <cstring>

using namespace std;

int mat[100][100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int k = 0; k < 4; k++) {
		int lx, ly, rx, ry;
		cin >> ly >> lx >> ry >> rx;
		ry -= 1;
		rx -= 1;
		for (int i = lx; i <= rx; i++) {
			for (int j = ly; j <= ry; j++) {
				mat[i][j] = 1;
			}
		}
	}

	int tmpmat[100][100];
	for (int i = 0; i < 100; i++) {
		memcpy(tmpmat[i], mat[99 - i], sizeof(mat[99 - i]));
	}

	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (mat[i][j] == 1) {
				ans += 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
