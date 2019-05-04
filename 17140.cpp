#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int mat[100][100];
int tmat[100][100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	int r, c, k;
	cin >> r >> c >> k;
	r -= 1, c -= 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> mat[i][j];
		}
	}

	int rowlen = 3, collen = 3;
	int t = 0;
	while (1) {
		if (t > 100) {
			t = -1;
			break;
		}
		if (mat[r][c] == k) {
			break;
		}
		
		memcpy(tmat, mat, sizeof(tmat));
		memset(mat, 0, sizeof(mat));

		if (rowlen >= collen) {
			for (int i = 0; i < 100; i++) {
				map<int, int> m;
				for (int j = 0; j < 100; j++) {
					if (tmat[i][j] == 0) continue;
					if (!m.count(tmat[i][j])) {
						m[tmat[i][j]] = 1;
					}
					else {
						m[tmat[i][j]] += 1;
					}
				}
				vector<pair<int, int>> v;
				for (auto it = m.begin(); it != m.end(); ++it) {
					v.push_back(make_pair(it->first, it->second));
				}
				sort(v.begin(), v.end(), [](auto &u, auto &v) {
					if (u.second == v.second) {
						return u.first < v.first;
					}
					return u.second < v.second;
				});

				for (int j = 0; j < v.size(); j++) {
					if (2 * j > 99) break;
					mat[i][2 * j] = v[j].first;
					mat[i][2 * j + 1] = v[j].second;
				}
			}

			collen = 0;
			for (int i = 0; i < 100; i++) {
				int idx = 100;
				for (int j = 0; j < 100; j++) {
					if (mat[i][j] == 0) {
						idx = j;
						break;
					}
				}
				if (idx > collen) {
					collen = idx;
				}
			}
		}
		else {
			for (int j = 0; j < 100; j++) {
				map<int, int> m;
				for (int i = 0; i < 100; i++) {
					if (tmat[i][j] == 0) continue;
					if (!m.count(tmat[i][j])) {
						m[tmat[i][j]] = 1;
					}
					else {
						m[tmat[i][j]] += 1;
					}
				}
				vector<pair<int, int>> v;
				for (auto it = m.begin(); it != m.end(); ++it) {
					v.push_back(make_pair(it->first, it->second));
				}
				sort(v.begin(), v.end(), [](auto &u, auto &v) {
					if (u.second == v.second) {
						return u.first < v.first;
					}
					return u.second < v.second;
				});
				for (int i = 0; i < v.size(); i++) {
					if (2 * i > 99) break;
					mat[2 * i][j] = v[i].first;
					mat[2 * i + 1][j] = v[i].second;
				}
			}

			rowlen = 0;
			for (int j = 0; j < 100; j++) {
				int idx = 100;
				for (int i = 0; i < 100; i++) {
					if (mat[i][j] == 0) {
						idx = i;
						break;
					}
				}
				if (idx > rowlen) {
					rowlen = idx;
				}
			}
		}
		t += 1;
	}

	cout << t << '\n';
	return 0;
}
