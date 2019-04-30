#include <tuple>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int mat[1000][1000];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc; cin >> tc;
	while (tc--) {
		int ans = -1;
		int n, m;
		cin >> m >> n;
		memset(mat, 0, sizeof(mat));
		queue<pair<int, int>> fire, person;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < m; j++) {
				if (s[j] == '#') mat[i][j] = -1;
				else if (s[j] == '*') {
					mat[i][j] = -1;
					fire.push(make_pair(i, j));
				}
				else if (s[j] == '@') {
					person.push(make_pair(i, j));
				}
			}
		}
		
		int time = 1;
		queue<pair<int, int>> nxt_fire, nxt_person;
		while (!person.empty()) {
			while (!fire.empty()) {
				int x, y;
				tie(x, y) = fire.front();
				fire.pop();

				for (int k = 0; k < 4; k++) {
					int tx = x + dx[k];
					int ty = y + dy[k];

					if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
					if (mat[tx][ty] == -1 || mat[tx][ty] > 0) continue;
					nxt_fire.push(make_pair(tx, ty));
					mat[tx][ty] = -1;
				}
			}

			while (!person.empty()) {
				int x, y;
				tie(x, y) = person.front();
				person.pop();

				for (int k = 0; k < 4; k++) {
					int tx = x + dx[k];
					int ty = y + dy[k];

					if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) {
						ans = time;
						goto end;
					}
					if (mat[tx][ty] == -1 || mat[tx][ty] > 0) continue;
					nxt_person.push(make_pair(tx, ty));
					mat[tx][ty] = time;
				}
			}
			
			fire = nxt_fire;
			person = nxt_person;
			nxt_person = queue<pair<int, int>>();
			nxt_fire = queue<pair<int, int>>();
			time += 1;
		}
end:
		if (ans == -1) cout << "IMPOSSIBLE\n";
		else cout << ans << '\n';
	}

	return 0;
}
