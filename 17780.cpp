#include <deque>
#include <iostream>

using namespace std;

struct MAL {
	int num, dir;
	MAL(int num = 0, int dir = 0)
		: num(num), dir(dir) {}
};

struct MatInfo {
	int color;
	deque<MAL> dq;
};

struct MALInfo {
	int x, y, dir;
	bool bot;
	MALInfo(int x = 0, int y = 0, int dir = 0, bool bot = false)
		: x(x), y(y), dir(dir), bot(bot) {}
};

MatInfo mat[12][12];
MALInfo MalInfo[11];
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

void move_color0(int x, int y, int tx, int ty) {
	while (mat[x][y].dq.size() > 0) {
		int tnum, tdir;
		tnum = mat[x][y].dq.back().num;
		tdir = mat[x][y].dq.back().dir;

		MalInfo[tnum].x = tx;
		MalInfo[tnum].y = ty;
		MalInfo[tnum].dir = tdir;
		MalInfo[tnum].bot = false;

		mat[tx][ty].dq.push_front(MAL(tnum, tdir));
		mat[x][y].dq.pop_back();
	}

	MalInfo[mat[tx][ty].dq.back().num].bot = true;
}

void move_color1(int x, int y, int tx, int ty) {
	while (mat[x][y].dq.size() > 0) {
		int tnum, tdir;
		tnum = mat[x][y].dq.front().num;
		tdir = mat[x][y].dq.front().dir;

		MalInfo[tnum].x = tx;
		MalInfo[tnum].y = ty;
		MalInfo[tnum].dir = tdir;
		MalInfo[tnum].bot = false;

		mat[tx][ty].dq.push_front(MAL(tnum, tdir));
		mat[x][y].dq.pop_front();
	}

	MalInfo[mat[tx][ty].dq.back().num].bot = true;
}

void move_color2(int dir, int j, int n, int x, int y, int tx, int ty) {
	if (dir == 1) dir = 2;
	else if (dir == 2) dir = 1;
	else if (dir == 3) dir = 4;
	else if (dir == 4) dir = 3;

	mat[x][y].dq.back().dir = dir;
	MalInfo[j].dir = dir;

	tx = x + dx[dir];
	ty = y + dy[dir];

	if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1 || mat[tx][ty].color == 2) {
		if (dir == 1) dir = 2;
		else if (dir == 2) dir = 1;
		else if (dir == 3) dir = 4;
		else if (dir == 4) dir = 3;

		mat[x][y].dq.back().dir = dir;
		MalInfo[j].dir = dir;
	}
	else if (mat[tx][ty].color == 0) {
		move_color0(x, y, tx, ty);
	}
	else if (mat[tx][ty].color == 1) {
		move_color1(x, y, tx, ty);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j].color;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		x -= 1, y -= 1;
		mat[x][y].dq.push_back(MAL(i + 1, d));
		MalInfo[i + 1] = MALInfo(x, y, d, true);
	}

	int ans = -1;
	for (int i = 1; ; i++) {
		if (i > 1000) break;

		for (int j = 1; j <= m; j++) {
			if (MalInfo[j].bot) {
				int dir = MalInfo[j].dir;
				int x = MalInfo[j].x;
				int y = MalInfo[j].y;
				int tx = x + dx[dir];
				int ty = y + dy[dir];

				if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1) {
					move_color2(dir, j, n, x, y, tx, ty);
				}
				else {
					int color = mat[tx][ty].color;
					if (color == 0) {
						move_color0(x, y, tx, ty);
					}
					else if (color == 1) {
						move_color1(x, y, tx, ty);
					}
					else if (color == 2) {
						move_color2(dir, j, n, x, y, tx, ty);
					}
				}
			}
		}

		bool ok = false;
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				if (mat[u][v].dq.size() >= 4) {
					ok = true;
				}
			}
		}
		if (ok) {
			ans = i;
			break;
		}
	}

	cout << ans << '\n';
	return 0;
}
