#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int mat[502][502];
int memo[502][502];
bool visit[502][502];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool go(int x, int y) {
	if (mat[x][y] == -1) {
		return true;
	}

	if (memo[x][y] > -1) {
		if (memo[x][y] == 0) {
			return false;
		}
		else {
			return true;
		}
	}

	if (visit[x][y] == true) {
		return false;
	}

	visit[x][y] = true;
	int tx = x + dx[mat[x][y]];
	int ty = y + dy[mat[x][y]];
	bool ok = go(tx, ty);
	if (ok) {
		memo[x][y] = 1;
	}
	else {
		memo[x][y] = 0;
	}
	
	return memo[x][y];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(mat, -1, sizeof(mat));
	memset(memo, -1, sizeof(memo));
	memset(visit, false, sizeof(visit));
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'U') {
				mat[i][j + 1] = 0;
			}
			else if (s[j] == 'R') {
				mat[i][j + 1] = 1;
			}
			else if (s[j] == 'D') {
				mat[i][j + 1] = 2;
			}
			else {
				mat[i][j + 1] = 3;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visit[i][j] == true) continue;
			go(i, j);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (memo[i][j] == 1) ans += 1;
		}
	}

	cout << ans << '\n';
	return 0;
}
