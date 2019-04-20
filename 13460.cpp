#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct NODE {
	int depth;
	int rx, ry, bx, by;
	NODE(int e, int a, int b, int c, int d) : depth(e), rx(a), ry(b), bx(c), by(d) {};
};

int mat[10][10];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool visit[10][10][10][10];

void move(int &x, int &y, int d) {
	while (1) {
		x += dx[d];
		y += dy[d];

		if (mat[x][y] == 1) {
			x -= dx[d];
			y -= dy[d];
			break;
		}
		if (mat[x][y] == 2) {
			break;
		}
	}
}

int r_x, r_y, b_x, b_y, h_x, h_y;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = -1;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			switch (s[j]) {
			case '.' :
				mat[i][j] = 0;
				break;
			case '#':
				mat[i][j] = 1;
				break;
			case 'O':
				mat[i][j] = 2;
				h_x = i;
				h_y = j;
				break;
			case 'R':
				r_x = i;
				r_y = j;
				break;
			case 'B':
				b_x = i;
				b_y = j;
				break;
			}
		}
	}

	queue<NODE> q;
	q.push(NODE(0, r_x, r_y, b_x, b_y));
	visit[r_x][r_y][b_x][b_y] = true;

	while (!q.empty()) {
		NODE node = q.front();
		q.pop();

		if (node.depth > 10) {
			break;
		}

		if (node.rx == h_x && node.ry == h_y) {
			ans = node.depth;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int rx = node.rx, ry = node.ry;
			int bx = node.bx, by = node.by;

			move(rx, ry, i);
			move(bx, by, i);

			if (bx == h_x && by == h_y) {
				continue;
			}

			if (rx == bx && ry == by) {
				switch (i) {
				case 0: 
					node.ry > node.by ? by-- : ry--;
					break;
				case 1: 
					node.ry > node.by ? ry++ : by++;
					break;
				case 2: 
					node.rx > node.bx ? bx-- : rx--;
					break;
				case 3:
					node.rx > node.bx ? rx++ : bx++;
					break;
				}
			}

			if (!visit[rx][ry][bx][by]) {
				q.push(NODE(node.depth + 1, rx, ry, bx, by));
				visit[rx][ry][bx][by] = true;
			}
		}
	}
  
	cout << ans << '\n';
	return 0;
}
