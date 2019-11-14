#include <deque>
#include <iostream>

using namespace std;

struct MAL {
	int num, x, y, d;
	MAL(int num = 0, int x = 0, int y = 0, int d = 0) :
		num(num), x(x), y(y), d(d) {}
};

struct Mat {
	int color;
	deque<MAL> dq;
};

int n, m;
Mat mat[13][13];
MAL mal_info[13];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void white_move(int mal, int x, int y, int tx, int ty, int turn) {
	int ssize = mat[x][y].dq.size();
	for (int i = 0; i < ssize; i++) {
		if (mat[x][y].dq[i].num == mal) {
			for (int j = i; j < ssize; j++) {
				int node = mat[x][y].dq[j].num;
				mat[tx][ty].dq.push_back(MAL(node, tx, ty, mat[x][y].dq[j].d));
				mal_info[node].x = tx;
				mal_info[node].y = ty;
			}

			mat[x][y].dq.erase(mat[x][y].dq.begin() + i, mat[x][y].dq.end());

			if (mat[tx][ty].dq.size() >= 4) {
				cout << turn << '\n';
				exit(0);
			}

			return;
		}
	}
}

void red_move(int mal, int x, int y, int tx, int ty, int turn) {
	int ssize = mat[x][y].dq.size();
	for (int i = 0; i < ssize; i++) {
		if (mat[x][y].dq[i].num == mal) {
			for (int j = ssize - 1; j >= i; j--) {
				int node = mat[x][y].dq[j].num;
				mat[tx][ty].dq.push_back(MAL(node, tx, ty, mat[x][y].dq[j].d));
				mal_info[node].x = tx;
				mal_info[node].y = ty;
			}

			mat[x][y].dq.erase(mat[x][y].dq.begin() + i, mat[x][y].dq.end());

			if (mat[tx][ty].dq.size() >= 4) {
				cout << turn << '\n';
				exit(0);
			}

			return;
		}
	}
}

void blue_move(int mal, int dir, int x, int y, int turn) {
	if (dir == 0) dir = 1;
	else if (dir == 1) dir = 0;
	else if (dir == 2) dir = 3;
	else if (dir == 3) dir = 2;

	mal_info[mal].d = dir;
	int tx = x + dx[dir];
	int ty = y + dy[dir];

	for (int i = 0; i < mat[x][y].dq.size(); i++) {
		if (mat[x][y].dq[i].num == mal) {
			mat[x][y].dq[i].d = dir;
			break;
		}
	}

	if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1) return;

	if (mat[tx][ty].color == 0) {
		white_move(mal, x, y, tx, ty, turn);
	}
	else if (mat[tx][ty].color == 1) {
		red_move(mal, x, y, tx, ty, turn);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j].color;
		}
	}
	
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		x -= 1;
		y -= 1;
		d -= 1;
		mat[x][y].dq.push_back(MAL(i + 1, x, y, d));

		mal_info[i + 1].num = i + 1;
		mal_info[i + 1].x = x;
		mal_info[i + 1].y = y;
		mal_info[i + 1].d = d;
	}

	int ans = -1;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= m; j++) {
			int x, y, dir;
			x = mal_info[j].x;
			y = mal_info[j].y;
			dir = mal_info[j].d;

			int tx = x + dx[dir];
			int ty = y + dy[dir];
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1) {
				blue_move(j, dir, x, y, i);
			}
			else {
				if (mat[tx][ty].color == 0) {
					white_move(j, x, y, tx, ty, i);
				}
				else if (mat[tx][ty].color == 1) {
					red_move(j, x, y, tx, ty, i);
				}
				else if (mat[tx][ty].color == 2) {
					blue_move(j, dir, x, y, i);
				}
			}
		}
	}

	cout << -1 << '\n';
	return 0;
}
