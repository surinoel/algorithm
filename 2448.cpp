#include <vector>
#include <iostream>

using namespace std;

vector<vector<char>> mat;
vector<int> bot_lv;

int findlv(int lv) {
	if (lv == 1) {
		return 0;
	}
	return findlv(lv / 2) + 1;
}

void go(int lv, int x, int y, int n) {
	if (lv == 0) {
		mat[x][y] = '*';
		mat[x + 1][y - 1] = mat[x + 1][y + 1] = '*';
		mat[x + 2][y - 2] = mat[x + 2][y - 1] = mat[x + 2][y] = mat[x + 2][y + 1] = mat[x + 2][y + 2] = '*';
		return;
	}

	go(lv - 1, x, y, n / 2);
	go(lv - 1, x + n / 2, y + (bot_lv[lv - 1] / 2 + 1), n / 2);
	go(lv - 1, x + n / 2, y - (bot_lv[lv - 1] / 2 + 1), n / 2);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int lv = findlv(n / 3);
	bot_lv.resize(lv + 1);
	bot_lv[0] = 5;
	for (int i = 1; i <= lv; i++) {
		bot_lv[i] = bot_lv[i - 1] * 2 + 1;
	}

	mat = vector<vector<char>>(n, vector<char>(bot_lv[lv]));
	go(lv, 0, bot_lv[lv] / 2, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < bot_lv[lv]; j++) {
			if (mat[i][j] == '*') {
				cout << mat[i][j];
			}
			else {
				cout << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
