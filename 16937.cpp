#include <vector>
#include <cstring>
#include <utility>
#include <iostream>

using namespace std;

int n, m, snum;
int mat[100][100];
int ans = 0;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> snum;	
	vector<pair<int, int>> st(snum);
	for (int i = 0; i < snum; i++) {
		int r, c;
		cin >> r >> c;
		st[i] = make_pair(r, c);
	}
	
	for (int i = 0; i < st.size(); i++) {
		int r1, c1, r2, c2;
		r1 = st[i].first;
		c1 = st[i].second;
		for (int rt = 0; rt < 2; rt++) {
			memset(mat, 0, sizeof(mat));
			swap(r1, c1);
			if (r1 > n || c1 > m) {
				continue;
			}
			for (int u = 0; u < r1; u++) {
				for (int v = 0; v < c1; v++) {
					mat[u][v] = 1;
				}
			}
			
			for (int j = 0; j < st.size(); j++) {
				if (i == j) continue;
				r2 = st[j].first;
				c2 = st[j].second;
				for (int rt = 0; rt < 2; rt++) {
					swap(r2, c2);
					bool ok = true;
					if (n - r2 < 0 || m - c2 < 0) {
						ok = false;
						continue;
					}
					for (int u = n - r2; u < n; u++) {
						for (int v = m - c2; v < m; v++) {
							if (mat[u][v] == 1) {
								ok = false;
								break;
							}
						}
						if (!ok) {
							break;
						}
					}
					if (ok) {
						if ((r1*c1 + r2*c2) > ans) {
							ans = r1*c1 + r2*c2;
						}
					}
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
