#include <tuple>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

int mat[25][25];
int group[25][25];
int group_size[25 * 25 + 1];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			mat[i][j] = s[j] - '0';
		}
	}

	int group_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 1 && group[i][j] == 0) {
				group[i][j] = ++group_num;
				group_size[group_num] = 1;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));

				while (!q.empty()) {
					int x, y;
					tie(x, y) = q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						int tx = x + dx[k];
						int ty = y + dy[k];

						if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1 || mat[tx][ty] == 0 || group[tx][ty] != 0) continue;
						group[tx][ty] = group_num;
						group_size[group_num] += 1;
						q.push(make_pair(tx, ty));
					}
				}
			}
		}
	}

	cout << group_num << '\n';
	sort(group_size + 1, group_size + 1 + group_num);
	for (int i = 1; i <= group_num; i++) {
		cout << group_size[i] << '\n';
	}

	return 0;
}
