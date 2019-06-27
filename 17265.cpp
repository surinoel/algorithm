#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

char mat[5][5];

int n;
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

pair<int,int> go(int x, int y, deque<int> dq1, deque<char> dq2) {
	if (x == n - 1 && y == n - 1) {
		while (!dq2.empty()) {
			int a, b; char op;
			a = dq1.front(); dq1.pop_front();
			op = dq2.front(); dq2.pop_front();
			b = dq1.front(); dq1.pop_front();
			int ans;
			switch (op) {
			case '+':
				ans = a + b;
				break;
			case '-':
				ans = a - b;
				break;
			case '*':
				ans = a * b;
				break;
			}
			dq1.push_front(ans);
		}
		return make_pair(dq1.front(), dq1.front());
	}

	pair<int,int> ret = { -1e9, 1e9 };
	for (int i = 0; i < 2; i++) {
		deque<int> tmp1(dq1);
		deque<char> tmp2(dq2);
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1) continue;
		if (mat[tx][ty] == '+' || mat[tx][ty] == '-' || mat[tx][ty] == '*') {
			tmp2.push_back(mat[tx][ty]);
		}
		else {
			tmp1.push_back(mat[tx][ty] - '0');
		}

		auto base = go(tx, ty, tmp1, tmp2);
		ret = make_pair(max(ret.first, base.first), min(ret.second, base.second));
	}

	return ret;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	deque<int> dq1;
	deque<char> dq2;
	dq1.push_back(mat[0][0] - '0');
	pair<int,int> ret = go(0, 0, dq1, dq2);
	cout << ret.first << ' ' << ret.second << '\n';
	return 0;
}
