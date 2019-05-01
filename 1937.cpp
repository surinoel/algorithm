#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct __node {
	int val, x, y;
} node;

int d[500][500];
int mat[500][500];
vector<node> v;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool cmp(const node &u, const node &v) {
	return u.val < v.val;
}

int main(void) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &mat[i][j]);
			d[i][j] = 1;
			v.push_back({ mat[i][j], i, j });
		}
	}
	sort(v.begin(), v.end(), cmp);
	int ans = 0;
	for (int i = 0; i < n*n; i++) {
		int x = v[i].x;
		int y = v[i].y;
		int t = 0;
		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1) continue;
			if (mat[x][y] > mat[tx][ty] && d[tx][ty] > t) {
				t = d[tx][ty];
			}
		}
		d[x][y] += t;
		if (d[x][y] > ans) ans = d[x][y];
	}
	printf("%d\n", ans);
	return 0;
}
