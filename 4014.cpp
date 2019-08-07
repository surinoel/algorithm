#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int mat[20][20];
bool rowbuild[20][20];
bool colbuild[20][20];
bool rowcheck[20];
bool colcheck[20];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	for (int test_case = 1; test_case <= tc; test_case++) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
			}
		}

		memset(rowbuild, false, sizeof(rowbuild));
		memset(colbuild, false, sizeof(colbuild));

		fill(rowcheck, rowcheck + n, true);
		fill(colcheck, colcheck + n, true);

		for (int i = 0; i < n; i++) {
			bool ok = true;
			int cmp;
			for (int j = 0; j < n; j++) {
				if (j == 0) {
					cmp = mat[i][j];
					continue;
				}
				if (mat[i][j] - cmp < 0) {
					if (cmp - mat[i][j] == 1) {
						bool ok = true;
						for (int k = 0; k < m; k++) {
							if (j + k >= n || mat[i][j + k] != mat[i][j] || rowbuild[i][j + k]) {
								rowcheck[i] = false;
								ok = false;
							}
						}
						if (ok) {
							for (int k = 0; k < m; k++) {
								rowbuild[i][j + k] = true;
							}
							j += (m - 1);
						}
					}
					else {
						rowcheck[i] = false;
					}
				}
				cmp = mat[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			bool ok = true;
			int cmp;
			if (!rowcheck[i]) continue;
			for (int j = n - 1; j >= 0; j--) {
				if (j == n -1) {
					cmp = mat[i][j];
					continue;
				}
				if (mat[i][j] - cmp < 0) {
					if (cmp - mat[i][j] == 1) {
						bool ok = true;
						for (int k = 0; k < m; k++) {
							if (j - k < 0 || mat[i][j - k] != mat[i][j] || rowbuild[i][j - k]) {
								rowcheck[i] = false;
								ok = false;
							}
						}
						if (ok) {
							for (int k = 0; k < m; k++) {
								rowbuild[i][j - k] = true;
							}
							j -= m;
							j += 1;
						}
					}
					else {
						rowcheck[i] = false;
					}
				}
				cmp = mat[i][j];
			}
		}
	
		for (int j = 0; j < n; j++) {
			bool ok = true;
			int cmp;
			for (int i = 0; i < n; i++) {
				if (i == 0) {
					cmp = mat[i][j];
					continue;
				}
				if (mat[i][j] - cmp < 0) {
					if (cmp - mat[i][j] == 1) {
						bool ok = true;
						for (int k = 0; k < m; k++) {
							if (i + k >= n || mat[i + k][j] != mat[i][j] || colbuild[i + k][j]) {
								colcheck[j] = false;
								ok = false;
							}
						}
						if (ok) {
							for (int k = 0; k < m; k++) {
								colbuild[i + k][j] = true;
							}
							i += (m - 1);
						}
					}
					else {
						colcheck[j] = false;
					}
				}
				cmp = mat[i][j];
			}

		}

		for (int j = 0; j < n; j++) {
			bool ok = true;
			int cmp;
			if (!colcheck[j]) continue;
			for (int i = n - 1; i >= 0; i--) {
				if (i == n - 1) {
					cmp = mat[i][j];
					continue;
				}
				if (mat[i][j] - cmp < 0) {
					if (cmp - mat[i][j] == 1) {
						bool ok = true;
						for (int k = 0; k < m; k++) {
							if (i - k < 0 || mat[i - k][j] != mat[i][j] || colbuild[i - k][j]) {
								colcheck[j] = false;
								ok = false;
							}
						}
						if (ok) {
							for (int k = 0; k < m; k++) {
								colbuild[i - k][j] = true;
							}
							i -= m;
							i += 1;
						}
					}
					else {
						colcheck[j] = false;
					}
				}
				cmp = mat[i][j];
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (rowcheck[i]) {
				ans += 1;
			}
			if (colcheck[i]) {
				ans += 1;
			}
		}
		cout << "#" << test_case << " " << ans << '\n';
	}
	
	return 0;
}
