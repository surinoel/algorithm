#include <tuple>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int mat[10][10];
int dist[10][10];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int sx, sy;
	cin >> sx >> sy;
	sx -= 1, sy -= 1;
	vector<pair<int, int>> wb;
	for (int i = 0; i < 10; i++) {
		string s; cin >> s;
		for (int j = 0; j < 10; j++) {
			if (s[j] == 'o') {
				mat[i][j] = -1;
				wb.push_back(make_pair(i, j));
			}
		}
	}
	
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	dist[sx][sy] = 0;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (tx < 0 || ty < 0 || tx > 9 || ty > 9 || mat[tx][ty] == -1 || dist[tx][ty] != -1) continue;
			dist[tx][ty] = dist[x][y] + 1;
			q.push(make_pair(tx, ty));
		}
	}
	
	for (int i = 0; i < wb.size(); i++) {
		int x, y;
		x = wb[i].first, y = wb[i].second;
		for (int j = 0; j < 10; j++) {
			mat[x][j] = -1;
		}
		for (int j = 0; j < 10; j++) {
			mat[j][y] = -1;
		}
	}

	int ans = -1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (mat[i][j] != -1 && (ans == -1 || ans > dist[i][j])) {
				ans = dist[i][j];
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
