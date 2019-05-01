#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int mat[5][5];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void go(int x, int y, int sum, int count, vector<int> &v) {
	if (count == 6) {
		v.push_back(sum);
		return;
	}

	for (int k = 0; k < 4; k++) {
		int tx = x + dx[k];
		int ty = y + dy[k];
		if (tx < 0 || ty < 0 || tx > 4 || ty > 4) continue;
		go(tx, ty, sum * 10 + mat[tx][ty], count + 1, v);
	}

	return;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> mat[i][j];
		}
	}

	vector<int> ans;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			go(i, j, mat[i][j], 1, ans);
		}
	}

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	cout << ans.size() << '\n';
	return 0;
}
