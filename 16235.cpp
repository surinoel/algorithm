#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Tree {
	int age;
	Tree(int age = 0) {
		this->age = age;
	}
};

bool cmp(const Tree &u, const Tree &v) {
	return u.age < v.age;
}

int mat[10][10];
int addmat[10][10];
vector<Tree> tree[10][10];

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, tc;
	cin >> n >> m >> tc;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = 5;
			cin >> addmat[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		x -= 1, y -= 1;
		tree[x][y].push_back(Tree(age));
	}

	for (int date = 1; date <= tc; date++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sort(tree[i][j].begin(), tree[i][j].end(), cmp);
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (mat[i][j] >= tree[i][j][k].age) {
						mat[i][j] -= tree[i][j][k].age;
						tree[i][j][k].age += 1;
					}
					else {
						for (int p = k; p < tree[i][j].size(); p++) {
							mat[i][j] += tree[i][j][p].age / 2;
						}
						tree[i][j].erase(tree[i][j].begin() + k, tree[i][j].end());
						break;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k].age % 5 == 0) {
						int x = i;
						int y = j;
						for (int u = 0; u < 8; u++) {
							int tx = x + dx[u];
							int ty = y + dy[u];
							if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1) continue;
							tree[tx][ty].push_back(Tree(1));
						}
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] += addmat[i][j];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += tree[i][j].size();
		}
	}
	cout << ans << '\n';
	return 0;
}
