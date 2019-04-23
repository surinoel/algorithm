#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<vector<int>> mat(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'C') {
				mat[i][j] = 1;
			}
			else if (s[j] == 'P') {
				mat[i][j] = 2;
			}
			else if (s[j] == 'Z') {
				mat[i][j] = 3;
			}
			else if (s[j] == 'Y') {
				mat[i][j] = 4;
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (mat[i][j] != mat[i][j + 1]) {
				vector<vector<int>> tmat(mat);
				int tmp = tmat[i][j];
				tmat[i][j] = tmat[i][j + 1];
				tmat[i][j + 1] = tmp;

				int cnt;
				int comp;
				for (int u = 0; u < n; u++) {
					cnt = 0;
					for (int v = 0; v < n; v++) {
						if (cnt == 0) {
							comp = tmat[u][v];
							cnt = 1;
							continue;
						}
						
						if (comp == tmat[u][v]) {
							cnt += 1;
						}
						else {
							if (ans == -1 || cnt > ans) {
								ans = cnt;
							}
							cnt = 1;
							comp = tmat[u][v];
						}
					}
					if (ans == -1 || cnt > ans) {
						ans = cnt;
					}
				}

				for (int u = 0; u < n; u++) {
					cnt = 0;
					for (int v = 0; v < n; v++) {
						if (cnt == 0) {
							comp = tmat[v][u];
							cnt = 1;
							continue;
						}

						if (comp == tmat[v][u]) {
							cnt += 1;
						}
						else {
							if (ans == -1 || cnt > ans) {
								ans = cnt;
							}
							cnt = 1;
							comp = tmat[v][u];
						}
					}
					if (ans == -1 || cnt > ans) {
						ans = cnt;
					}
				}
			}
		}
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (mat[i][j] != mat[i + 1][j]) {
				vector<vector<int>> tmat(mat);
				int tmp = tmat[i][j];
				tmat[i][j] = tmat[i + 1][j];
				tmat[i + 1][j] = tmp;

				int cnt;
				int comp;
				for (int u = 0; u < n; u++) {
					cnt = 0;
					for (int v = 0; v < n; v++) {
						if (cnt == 0) {
							comp = tmat[u][v];
							cnt = 1;
							continue;
						}

						if (comp == tmat[u][v]) {
							cnt += 1;
						}
						else {
							if (ans == -1 || cnt > ans) {
								ans = cnt;
							}
							cnt = 1;
							comp = tmat[u][v];
						}
					}
					if (ans == -1 || cnt > ans) {
						ans = cnt;
					}
				}

				for (int u = 0; u < n; u++) {
					cnt = 0;
					for (int v = 0; v < n; v++) {
						if (cnt == 0) {
							comp = tmat[v][u];
							cnt = 1;
							continue;
						}

						if (comp == tmat[v][u]) {
							cnt += 1;
						}
						else {
							if (ans == -1 || cnt > ans) {
								ans = cnt;
							}
							cnt = 1;
							comp = tmat[v][u];
						}
					}
					if (ans == -1 || cnt > ans) {
						ans = cnt;
					}
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
