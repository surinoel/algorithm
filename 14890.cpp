#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d;
	cin >> n >> d;
	vector<vector<pair<int, bool>>> row(n, vector<pair<int, bool>>(n, { 0, false }));
	vector<vector<pair<int, bool>>> col(n, vector<pair<int, bool>>(n, { 0, false }));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> row[i][j].first;
			col[i][j].first = row[i][j].first;
		}
	}
	
	int ans = 0;
	vector<bool> rcheck(n, true), ccheck(n, true);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (row[i][j + 1].first - row[i][j].first >= 1) {
				if (row[i][j + 1].first - row[i][j].first == 1) {
					bool ok = true;
					for (int k = j; k >= j - d + 1; k--) {
						if ((!(k >= 0 && k <= n - 1)) || row[i][k].first != row[i][j].first || row[i][k].second == true) {
							ok = false;
							break;
						}
					}
					if (ok) {
						for (int k = j; k >= j - d + 1; k--) {
							row[i][k].second = true;
						}
					}
					else {
						rcheck[i] = false;
					}
				}
				else {
					rcheck[i] = false;
				}
			}
		}

		for (int j = n - 1; j >= 1; j--) {
			if (rcheck[i] == false) continue;
			if (row[i][j - 1].first - row[i][j].first >= 1) {
				if (row[i][j - 1].first - row[i][j].first == 1) {
					bool ok = true;
					for (int k = j; k <= j + d - 1; k++) {
						if ((!(k >= 0 && k <= n - 1)) || row[i][k].first != row[i][j].first || row[i][k].second == true) {
							ok = false;
							break;
						}
					}
					if (ok) {
						for (int k = j; k <= j + d - 1; k++) {
							row[i][k].second = true;
						}
					}
					else {
						rcheck[i] = false;
					}
				}
				else {
					rcheck[i] = false;
				}
			}
		}
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (col[i + 1][j].first - col[i][j].first >= 1) {
				if (col[i + 1][j].first - col[i][j].first == 1) {
					bool ok = true;
					for (int k = i; k >= i - d + 1; k--) {
						if ((!(k >= 0 && k <= n - 1)) || (col[k][j].first != col[i][j].first) || col[k][j].second == true) {
							ok = false;
							break;
						}
					}
					if (ok) {
						for (int k = i; k >= i - d + 1; k--) {
							col[k][j].second = true;
						}
					}
					else {
						ccheck[j] = false;
					}
				}
				else {
					ccheck[j] = false;
				}
			}
		}

		for (int i = n - 1; i >= 1; i--) {
			if (ccheck[j] == false) continue;
			if (col[i - 1][j].first - col[i][j].first >= 1) {
				if (col[i - 1][j].first - col[i][j].first == 1) {
					bool ok = true;
					for (int k = i; k <= i + d - 1; k++) {
						if ((!(k >= 0 && k <= n - 1)) || col[k][j].first != col[i][j].first || col[k][j].second == true) {
							ok = false;
							break;
						}
					}
					if (ok) {
						for (int k = i; k <= i + d - 1; k++) {
							col[k][j].second = true;
						}
					}
					else {
						ccheck[j] = false;
					}
				}
				else {
					ccheck[j] = false;
				}
			}
		}
	}

	for (int k = 0; k < n; k++) {
		if (rcheck[k]) ans += 1;
		if (ccheck[k]) ans += 1;
	}

	cout << ans << '\n';
	return 0;
}
