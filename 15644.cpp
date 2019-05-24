#include <tuple>
#include <queue>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

typedef struct __node {
	int rx, ry, bx, by;
	long long mask;
	__node(int _rx, int _ry, int _bx, int _by, long long _mask) : 
		rx(_rx), ry(_ry), bx(_bx), by(_by), mask(_mask) {}
} node;

int n, m;
int rx, ry, bx, by, hx, hy;
int mat[10][10];
int dist[10][10][10][10];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void move(int &x, int &y, int dir) {
	while (1) {
		if (x == hx && y == hy) {
			return;
		}
		else if (mat[x][y] == -1) {
			x -= dx[dir];
			y -= dy[dir];
			return;
		}
		x += dx[dir];
		y += dy[dir];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '#') {
				mat[i][j] = -1;
			}
			else if (s[j] == 'R') {
				rx = i;
				ry = j;
			}
			else if (s[j] == 'B') {
				bx = i;
				by = j;
			}
			else if (s[j] == 'O') {
				hx = i;
				hy = j;
			}
		}
	}

	memset(dist, -1, sizeof(dist));
	dist[rx][ry][bx][by] = 0;
	queue<node> q;
	q.push(node(rx, ry, bx, by, 0));

	int ans = -1;
	while (!q.empty()) {
		node b = q.front();		
		q.pop();
		
        if (dist[b.rx][b.ry][b.bx][b.by] > 10) {
			break;
		}
        
		if (b.rx == hx && b.ry == hy) {
			cout << dist[b.rx][b.ry][b.bx][b.by] << '\n';
			string s = to_string(b.mask);
			for (int i = 0; i < s.size(); i++) {
				switch (s[i]) {
				case '1':
					cout << "L";
					break;
				case '2':
					cout << "R";
					break;
				case '3':
					cout << "U";
					break;
				case '4':
					cout << "D";
					break;
				}
			}
			cout << '\n';
			return 0;
		}

		for (int k = 0; k < 4; k++) {
			int rrx = b.rx, rry = b.ry, bbx = b.bx, bby = b.by;
			move(bbx, bby, k);
			if (bbx == hx && bby == hy) {
				continue;
			}
			move(rrx, rry, k);

			if (rrx == bbx && rry == bby) {
				switch (k) {
				case 0:
					b.ry > b.by ? rry++ : bby++;
					break;
				case 1:
					b.ry > b.by ? bby-- : rry--;
					break;
				case 2:
					b.rx > b.bx ? rrx++ : bbx++;
					break;
				case 3:
					b.rx > b.bx ? bbx-- : rrx--;
					break;
				}
			}
			
			if (dist[rrx][rry][bbx][bby] == -1) {
				dist[rrx][rry][bbx][bby] = dist[b.rx][b.ry][b.bx][b.by] + 1;
				if (b.mask == 0) {
					q.push(node(rrx, rry, bbx, bby, k + 1));
				}
				else {
					q.push(node(rrx, rry, bbx, bby, b.mask * 10 + (k + 1)));
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
