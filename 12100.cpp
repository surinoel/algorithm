#include <vector>
#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m

int n;
int ans = -1;

void go(int cnt, vector<vector<int>>& mat) {
	if (cnt == 5) {
		int tmp = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp = max(tmp, mat[i][j]);
			}
		}
		ans = max(ans, tmp);
		return;
	}
	
	vector<vector<int>> tmpmat(mat);
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			int val = tmpmat[i][j];
			for (int k = i - 1; k >= 0; k--) {
				if (tmpmat[k][j] != 0) {
					tmpmat[i][j] = 0;
					tmpmat[k + 1][j] = val;
					break;
				}
				else if (tmpmat[k][j] == 0 && k == 0) {
					tmpmat[i][j] = 0;
					tmpmat[k][j] = val;
				}
			}
		}

		int start = tmpmat[0][j];
		for (int i = 1; i < n; i++) {
			if (start == tmpmat[i][j]) {
				tmpmat[i - 1][j] *= 2;
				tmpmat[i][j] = 0;
				if (i + 1 < n) {
					start = tmpmat[i + 1][j];
					i += 1;
				}
			}
			else {
				start = tmpmat[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			int val = tmpmat[i][j];
			for (int k = i - 1; k >= 0; k--) {
				if (tmpmat[k][j] != 0) {
					tmpmat[i][j] = 0;
					tmpmat[k + 1][j] = val;
					break;
				}
				else if (tmpmat[k][j] == 0 && k == 0) {
					tmpmat[i][j] = 0;
					tmpmat[k][j] = val;
				}
			}
		}
	}
	go(cnt + 1, tmpmat);

	tmpmat = mat;
	for (int j = 0; j < n; j++) {
		for (int i = n - 1; i >= 0; i--) {
			int val = tmpmat[i][j];
			for (int k = i + 1; k < n; k++) {
				if (tmpmat[k][j] != 0) {
					tmpmat[i][j] = 0;
					tmpmat[k - 1][j] = val;
					break;
				}
				else if (tmpmat[k][j] == 0 && k == n - 1) {
					tmpmat[i][j] = 0;
					tmpmat[k][j] = val;
				}
			}
		}

		int start = tmpmat[n - 1][j];
		for (int i = n - 2; i >= 0; i--) {
			if (start == tmpmat[i][j]) {
				tmpmat[i + 1][j] *= 2;
				tmpmat[i][j] = 0;
				if (i - 1 >= 0) {
					start = tmpmat[i - 1][j];
					i -= 1;
				}
			}
			else {
				start = tmpmat[i][j];
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			int val = tmpmat[i][j];
			for (int k = i + 1; k < n; k++) {
				if (tmpmat[k][j] != 0) {
					tmpmat[i][j] = 0;
					tmpmat[k - 1][j] = val;
					break;
				}
				else if (tmpmat[k][j] == 0 && k == n - 1) {
					tmpmat[i][j] = 0;
					tmpmat[k][j] = val;
				}
			}
		}
	}
	go(cnt + 1, tmpmat);

	tmpmat = mat;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int val = tmpmat[i][j];
			for (int k = j - 1; k >= 0; k--) {
				if (tmpmat[i][k] != 0) {
					tmpmat[i][j] = 0;
					tmpmat[i][k + 1] = val;
					break;
				}
				else if (tmpmat[i][k] == 0 && k == 0) {
					tmpmat[i][j] = 0;
					tmpmat[i][k] = val;
				}
			}
		}
		int start = tmpmat[i][0];
		for (int j = 1; j < n; j++) {
			if (start == tmpmat[i][j]) {
				tmpmat[i][j - 1] *= 2;
				tmpmat[i][j] = 0;
				if (j + 1 < n) {
					start = tmpmat[i][j + 1];
					j += 1;
				}
			}
			else {
				start = tmpmat[i][j];
			}
		}

		for (int j = 0; j < n; j++) {
			int val = tmpmat[i][j];
			for (int k = j - 1; k >= 0; k--) {
				if (tmpmat[i][k] != 0) {
					tmpmat[i][j] = 0;
					tmpmat[i][k + 1] = val;
					break;
				}
				else if (tmpmat[i][k] == 0 && k == 0) {
					tmpmat[i][j] = 0;
					tmpmat[i][k] = val;
				}
			}
		}
	}
	go(cnt + 1, tmpmat);

	tmpmat = mat;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			int val = tmpmat[i][j];
			for (int k = j + 1; k < n; k++) {
				if (tmpmat[i][k] != 0) {
					tmpmat[i][j] = 0;
					tmpmat[i][k - 1] = val;
					break;
				}
				else if (tmpmat[i][k] == 0 && k == n - 1) {
					tmpmat[i][j] = 0;
					tmpmat[i][k] = val;
				}
			}
		}

		int start = tmpmat[i][n - 1];
		for (int j = n - 2; j >= 0; j--) {
			if (start == tmpmat[i][j]) {
				tmpmat[i][j + 1] *= 2;
				tmpmat[i][j] = 0;
				if (j - 1 >= 0) {
					start = tmpmat[i][j - 1];
					j -= 1;
				}
			}
			else {
				start = tmpmat[i][j];
			}
		}

		for (int j = n - 1; j >= 0; j--) {
			int val = tmpmat[i][j];
			for (int k = j + 1; k < n; k++) {
				if (tmpmat[i][k] != 0) {
					tmpmat[i][j] = 0;
					tmpmat[i][k - 1] = val;
					break;
				}
				else if (tmpmat[i][k] == 0 && k == n - 1) {
					tmpmat[i][j] = 0;
					tmpmat[i][k] = val;
				}
			}
		}
	}
	go(cnt + 1, tmpmat);

	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vector<vector<int>> mat(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	go(0, mat);
	cout << ans << '\n';
	return 0;
}
