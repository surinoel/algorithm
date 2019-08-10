#include <queue>
#include <tuple>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct __shark {
	int x, y;
	int size;
	int cnt;
	__shark() {}
	__shark(int rx, int ry, int s, int c) : x(rx), y(ry), size(s), cnt(c) {}
} Shark;

int n;
int mat[20][20];
int dist[20][20];
Shark sh;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(vector<tuple<int, int, int>> &v) {
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;
	dist[sh.x][sh.y] = 0;
	q.push(make_pair(sh.x, sh.y));
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1) continue;
			if (dist[tx][ty] != -1) continue;
			if (mat[tx][ty] > sh.size) continue;
			dist[tx][ty] = dist[x][y] + 1;
			q.push(make_pair(tx, ty));
			if (mat[tx][ty] != 0 && mat[tx][ty] != 9) {
				if (mat[tx][ty] < sh.size) {
					v.push_back(make_tuple(dist[tx][ty], tx, ty));
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 9) {
				sh.x = i;
				sh.y = j;
				sh.size = 2;
				sh.cnt = 0;
			}
		}
	}
	int t = 0;
	while (true) {
		vector<tuple<int, int, int>> tmp;
		bfs(tmp);
		if (tmp.empty()) {
			break;
		}

		sort(tmp.begin(), tmp.end());

		mat[sh.x][sh.y] = 0;
		int tt, x, y;
		tie(tt, x, y) = tmp.front();
		t += tt;
		sh.x = x;
		sh.y = y;
		if (++sh.cnt == sh.size) {
			sh.size += 1;
			sh.cnt = 0;
		}
	}

	cout << t << '\n';
	return 0;
}
