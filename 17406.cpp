#include <deque>
#include <tuple>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int mat[50][50];
int tmat[50][50];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void circle_mat(int (*m)[50], int x, int y, int range) {
	for (int i = 1; i <= range; i++) {
		int sx = x - i;
		int sy = y - i;
		deque<int> dq;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 2 * i; k++) {
				sx += dx[j];
				sy += dy[j];
				dq.push_back(m[sx][sy]);
			}
		}
		int val = dq.back();
		dq.pop_back();
		dq.push_front(val);

		sx = x - i;
		sy = y - i;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 2 * i; k++) {
				sx += dx[j];
				sy += dy[j];
				m[sx][sy] = dq.front();
				dq.pop_front();
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	vector<tuple<int, int, int>> clist(k);
	for (int i = 0; i < k; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x -= 1;
		y -= 1;
		clist[i] = make_tuple(x, y, z);
	}

	vector<int> idx(k);
	for (int i = 0; i < k; i++) {
		idx[i] = i;
	}
	
	int ans = -1;
	do {
		memcpy(tmat, mat, sizeof(mat));
		for (int i = 0; i < idx.size(); i++) {
			circle_mat(tmat, get<0>(clist[idx[i]]), get<1>(clist[idx[i]]), get<2>(clist[idx[i]]));
		}

		for (int i = 0; i < n; i++) {
			int tsum = 0;
			for (int j = 0; j < m; j++) {
				tsum += tmat[i][j];
			}
			if (ans == -1 || ans > tsum) {
				ans = tsum;
			}
		}
	} while (next_permutation(idx.begin(), idx.end()));

	cout << ans << '\n';
	return 0;
}
