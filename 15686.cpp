#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int mat[50][50] = { {0} };
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> h, c;
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 1) {
				h.push_back(make_pair(i, j));
			}
			else if (mat[i][j] == 2) {
				num++;
				c.push_back(make_pair(i, j));
			}
		}
	}

	vector<int> chk(num);
	for (int i = 0; i < m; i++) {
		chk[i] = 1;
	}
	for (int i = m; i < num; i++) {
		chk[i] = 0;
	}

	int ans = -1;
	do {
		vector<pair<int, int>> tmp;
		for (int i = 0; i < num; i++) {
			if (chk[i] == 1) {
				tmp.push_back(c[i]);
			}
		}
		int sum = 0;
		for (int i = 0; i < h.size(); i++) {
			int x, y;
			tie(x, y) = h[i];
			int len = -1;
			for (int j = 0; j < tmp.size(); j++) {
				int cx, cy;
				tie(cx, cy) = tmp[j];
				int lentmp = abs(x - cx) + abs(y - cy);
				if (len == -1 || len > lentmp) {
					len = lentmp;
				}
			}
			sum += len;
		}

		if (ans == -1 || ans > sum) {
			ans = sum;
		}
	} while (prev_permutation(chk.begin(), chk.end()));

	cout << ans << '\n';
	return 0;
}
