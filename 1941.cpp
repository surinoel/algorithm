#include <string>
#include <iostream>

using namespace std;

int mat[5][5];
bool visit[(1 << 25)];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void go(int x, int y, int xy, int sum, int cnt, int &ans) {
	if (visit[xy]) return;
	if (cnt == 7) {
		visit[xy] = true;
		if (sum >= 4) ans += 1;
		return;
	}
	
	visit[xy] = true;
	for (int i = 0; i < 25; i++) {
		if (!(xy & (1 << i))) continue;
		int tx = i / 5;
		int ty = i % 5;
		for (int k = 0; k < 4; k++) {
			int ttx = tx + dx[k];
			int tty = ty + dy[k];
			if (ttx < 0 || tty < 0 || ttx > 4 || tty > 4) continue;
			go(ttx, tty, xy | (1 << (ttx * 5 + tty)), sum + mat[ttx][tty], cnt + 1, ans);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 5; i++) {
		string s; cin >> s;
		for (int j = 0; j < 5; j++) {
			if (s[j] == 'S') mat[i][j] = 1;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			go(i, j, (1 << (5 * i + j)), mat[i][j], 1, ans);
		}
	}
	cout << ans << '\n';
	return 0;
}
