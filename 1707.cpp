#include <vector>
#include <iostream>

using namespace std;

int check[20001];
vector<int> mat[20001];

bool go(int idx, int val) {
	check[idx] = val;
	for (int i = 0; i < mat[idx].size(); i++) {
		int y = mat[idx][i];
		if (check[y] == 0) {
			if (!go(y, 3 - val)) return false;
		}
		else if (check[y] == check[idx]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(check, 0, sizeof(check));
		int n, m;
		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			mat[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			mat[x].push_back(y);
			mat[y].push_back(x);
		}

		bool ok = true;
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) {
				if (!go(i, 1)) {
					ok = false;
					break;
				}
			}
		}
		
		if (ok) {
			for (int i = 1; i <= n; i++) {
				int x = check[i];
				for (int j = 0; j < mat[i].size(); j++) {
					int node = mat[i][j];
					if (x == check[node]) {
						cout << "NO\n";
						return 0;
					}
				}
			}
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}

	return 0;
}
