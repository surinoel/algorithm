#include <cstdio>
#include <vector>

using namespace std;

#define max(n, m) n > m ? n : m

int mat[50][50];
int dx[2] = { 1, 1 };
int dy[2] = { 0, 1 };

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &mat[i][j]);
		}
	}

	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num = mat[i][j];
			vector<int> edge;
			for (int k = j + 1; k < m; k++) {
				if (mat[i][k] == num) {
					edge.push_back(k);
				}
			}
			for (int k = 0; k < edge.size(); k++) {
				bool ok = true;
				int len = edge[k] - j;
				for (int u = 0; u < 2; u++) {
					int tx = i + dx[u] * len;
					int ty = j + dy[u] * len;
					if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || mat[tx][ty] != num) {
						ok = false;
						break;
					}
				}
				if (ok) {
					ans = max(ans, (len + 1) * (len + 1));
				}
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
