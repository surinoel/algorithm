#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int snail[1000][1000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, val;
	cin >> n >> val;

	int start = pow(n, 2);
	// 방향 설정
	// 아래, 오른쪽, 위, 왼쪽
	int dir = 0;
	int x, y;
	x = -1, y = 0;

	while (start >= 1) {
		switch (dir % 4) {
		case 0:
			if (x + 1 > n - 1 || snail[x + 1][y] != 0) {
				dir = (dir + 1) % 4;
			}
			else {
				x++;
				snail[x][y] = start--;
			}
			break;
		case 1:
			if (y + 1 > n - 1 || snail[x][y + 1] != 0) {
				dir = (dir + 1) % 4;
			}
			else {
				y++;
				snail[x][y] = start--;
			}
			break;
		case 2:
			if (x - 1 < 0 || snail[x - 1][y] != 0) {
				dir = (dir + 1) % 4;
			}
			else {
				x--;
				snail[x][y] = start--;
			}
			break;
		case 3:
			if (y - 1 < 0 || snail[x][y - 1] != 0) {
				dir = (dir + 1) % 4;
			}
			else {
				y--;
				snail[x][y] = start--;
			}
			break;
		}
	}

	int ansx, ansy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << snail[i][j] << ' ';
			if (snail[i][j] == val) {
				ansx = i + 1, ansy = j + 1;
			}
		}
		cout << '\n';
	}

	cout << ansx << ' ' << ansy << '\n';

	return 0;
}