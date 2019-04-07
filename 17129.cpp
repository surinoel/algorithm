#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int mat[3000][3000];
int dist[3000][3000];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);

	int n, m;
	int sx, sy, ex1, ey1, ex2, ey2, ex3, ey3;
	cin >> n >> m;
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<s.size(); j++) {
			mat[i][j] = s[j] - '0';
			if (mat[i][j] == 2) {
				sx = i;
				sy = j;
				q.push(make_pair(sx, sy));
				dist[sx][sy] = 0;
			}
			else if (mat[i][j] == 3) {
				ex1 = i, ey1 = j;
			}
			else if (mat[i][j] == 4) {
				ex2 = i, ey2 = j;
			}
			else if (mat[i][j] == 5) {
				ex3 = i, ey3 = j;
			}
		}
	}

	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
			if (dist[tx][ty] != -1 || mat[tx][ty] == 1) continue;
			dist[tx][ty] = dist[x][y] + 1;
			q.push(make_pair(tx, ty));
		}
	}
	
	int mxval, mnval;
	mxval = max(dist[ex1][ey1], max(dist[ex2][ey2], dist[ex3][ey3]));
	
	if (mxval == -1) {
		cout << "NIE\n";
	}
	else {
		cout << "TAK\n";
		vector<int> ans(3);
		ans[0] = dist[ex1][ey1];
		ans[1] = dist[ex2][ey2];
		ans[2] = dist[ex3][ey3];
		sort(ans.begin(), ans.end());
		
		for (auto it : ans) {
			if (it == -1) continue;
			cout << it << '\n';
			break;
		}
	}

	return 0;
}