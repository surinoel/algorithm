#include <iostream>
#include <deque>
#include <tuple>

using namespace std;

int mat[100][100];
int d[10001];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;
		mat[x - 1][y - 1] = 2;
	}
	
	cin >> k;
	char c; int end;
	int start = 1;
	int dir = 0;
	while (k--) {
		cin >> end;
 		for (int i = start; i <= end; i++) {
			d[i] = dir;
		}
		cin >> c;
		if (c == 'L') {
			if (++dir == 4) {
				dir = 0;
			}
		}
		else {
			if (--dir == -1) {
				dir = 3;
			}
		}
		start = end + 1;
	}
	for (int i = start; i <= 10000; i++) {
		d[i] = dir;
	}

	deque<pair<int, int>> q;
	q.push_back(make_pair(0, 0));
	mat[0][0] = 1;
	int time = 1;
	
	while (true) {
		int x, y;
		tie(x, y) = q.front();
		int tx = x + dx[d[time]];
		int ty = y + dy[d[time]];
		if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1) {
			break;
		}
		if (mat[tx][ty] == 1) {
			break;
		}
		else if (mat[tx][ty] == 2) {
			mat[tx][ty] = 1;
			q.push_front(make_pair(tx, ty));
		}
		else {
			deque<pair<int, int>>::iterator it;
			it = q.end() - 1;
			mat[it->first][it->second] = 0;
			q.pop_back();
			mat[tx][ty] = 1;
			q.push_front(make_pair(tx, ty));
		}
		time++;
	}

	cout << time << '\n';
	return 0;
}
