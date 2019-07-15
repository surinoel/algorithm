#include <tuple>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

int mat[250][250];
int group[250][250];
pair<int, int> group_size[250 * 250 + 1];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '#') mat[i][j] = -1;
			else if (s[j] == 'v') mat[i][j] = 2;
			else if (s[j] == 'o') mat[i][j] = 3;
		}
	}

	int ans1 = 0, ans2 = 0;
	int group_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == -1 || group[i][j] != 0) continue;
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			group[i][j] = ++group_num;
			if (mat[i][j] == 2) group_size[group_num].first += 1;
			else if (mat[i][j] == 3) group_size[group_num].second += 1;

			while (!q.empty()) {
				int x, y;
				tie(x, y) = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int tx = x + dx[k];
					int ty = y + dy[k];
					if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || mat[tx][ty] == -1 || group[tx][ty] != 0) continue;
					group[tx][ty] = group_num;
					if (mat[tx][ty] == 2) group_size[group_num].first += 1;
					else if (mat[tx][ty] == 3) group_size[group_num].second += 1;
					q.push(make_pair(tx, ty));
				}
			}
			
			if (group_size[group_num].first >= group_size[group_num].second) {
				ans1 += group_size[group_num].first;
			}
			else {
				ans2 += group_size[group_num].second;
			}
		}
	}

	cout << ans2 << ' ' << ans1 << '\n';
	return 0;
}
