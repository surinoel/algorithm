#include <string>
#include <iostream>

using namespace std;

int mat[25][25];
int n, m;
int ex, ey;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int block_dir[8][4] = { // 각 블럭이 개방된 방향
	{0, 0, 0, 0},
	{1, 1, 0, 0},
	{0, 0, 1, 1},
	{1, 1, 1, 1},
	{1, 0, 1, 0},
	{0, 1, 1, 0},
	{0, 1, 0, 1},
	{1, 0, 0, 1}
};

bool check(int x, int y, int kind)
{
  // 도착점이 Z라면 무조건 true
	if (x - 1 >= 0 && mat[x - 1][y] == 9) return true;
	if (x + 1 < n && mat[x + 1][y] == 9) return true;
	if (y - 1 >= 0 && mat[x][y - 1] == 9) return true;
	if (y + 1 < m && mat[x][y + 1] == 9) return true;
  
  // 양쪽이랑 연결되어야 한다
	if (kind == 1) {
		if (x - 1 >= 0 && block_dir[mat[x - 1][y]][0] == 0) return false;
		if (x + 1 < n && block_dir[mat[x + 1][y]][1] == 0) return false;
		if (y - 1 >= 0 && block_dir[mat[x][y - 1]][2] == 1) return false;
		if (y + 1 < m && block_dir[mat[x][y + 1]][3] == 1) return false;
	}
	else if (kind == 2) {
		if (x - 1 >= 0 && block_dir[mat[x - 1][y]][0] == 1) return false;
		if (x + 1 < n && block_dir[mat[x + 1][y]][1] == 1) return false;
		if (y - 1 >= 0 && block_dir[mat[x][y - 1]][2] == 0) return false;
		if (y + 1 < m && block_dir[mat[x][y + 1]][3] == 0) return false;
	}
	else if (kind == 3) {
		if (x - 1 >= 0 && block_dir[mat[x - 1][y]][0] == 0) return false;
		if (x + 1 < n && block_dir[mat[x + 1][y]][1] == 0) return false;
		if (y - 1 >= 0 && block_dir[mat[x][y - 1]][2] == 0) return false;
		if (y + 1 < m && block_dir[mat[x][y + 1]][3] == 0) return false;
	}
	else if (kind == 4) {
		if (x - 1 >= 0 && block_dir[mat[x - 1][y]][0] == 1) return false;
		if (x + 1 < n && block_dir[mat[x + 1][y]][1] == 0) return false;
		if (y - 1 >= 0 && block_dir[mat[x][y - 1]][2] == 1) return false;
		if (y + 1 < m && block_dir[mat[x][y + 1]][3] == 0) return false;
	}
	else if (kind == 5) {
		if (x - 1 >= 0 && block_dir[mat[x - 1][y]][0] == 0) return false;
		if (x + 1 < n && block_dir[mat[x + 1][y]][1] == 1) return false;
		if (y - 1 >= 0 && block_dir[mat[x][y - 1]][2] == 1) return false;
		if (y + 1 < m && block_dir[mat[x][y + 1]][3] == 0) return false;
	}
	else if (kind == 6) {
		if (x - 1 >= 0 && block_dir[mat[x - 1][y]][0] == 0) return false;
		if (x + 1 < n && block_dir[mat[x + 1][y]][1] == 1) return false;
		if (y - 1 >= 0 && block_dir[mat[x][y - 1]][2] == 0) return false;
		if (y + 1 < m && block_dir[mat[x][y + 1]][3] == 1) return false;
	}
	else if (kind == 7) {
		if (x - 1 >= 0 && block_dir[mat[x - 1][y]][0] == 1) return false;
		if (x + 1 < n && block_dir[mat[x + 1][y]][1] == 0) return false;
		if (y - 1 >= 0 && block_dir[mat[x][y - 1]][2] == 0) return false;
		if (y + 1 < m && block_dir[mat[x][y + 1]][3] == 1) return false;
	}

	return true;
}

void go(int x, int y, int dir, int px, int py, int kind) {
	if (x == ex && y == ey) {
		cout << px + 1 << ' ' << py + 1 << ' ';
		if (kind == 1) cout << "|\n";
		else if (kind == 2) cout << "-\n";
		else if (kind == 3) cout << "+\n";
		else if (kind == 4) cout << "1\n";
		else if (kind == 5) cout << "2\n";
		else if (kind == 6) cout << "3\n";
		else if (kind == 7) cout << "4\n";
		exit(0);
	}

	if (dir == -1) { 
		bool ok = false;
		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || mat[tx][ty] == 0) continue;
			ok = true;
			go(tx, ty, k, px, py, kind);
		}

		if (!ok && kind == -1) {
			for (int k = 0; k < 4; k++) {
				int tx = x + dx[k];
				int ty = y + dy[k];
				if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
				if (k == 0) {
					if (check(tx, ty, 1)) {
						mat[tx][ty] = 1;
						go(tx, ty, k, tx, ty, 1);
					}
					if (check(tx, ty, 3)) {
						mat[tx][ty] = 3;
						go(tx, ty, k, tx, ty, 3);
					}
					if (check(tx, ty, 5)) {
						mat[tx][ty] = 5;
						go(tx, ty, k, tx, ty, 5);
					}
					if (check(tx, ty, 6)) {
						mat[tx][ty] = 6;
						go(tx, ty, k, tx, ty, 6);
					}
					mat[tx][ty] = 0;
				}
				else if (k == 1) {
					if (check(tx, ty, 1)) {
						mat[tx][ty] = 1;
						go(tx, ty, k, tx, ty, 1);
					}
					if (check(tx, ty, 3)) {
						mat[tx][ty] = 3;
						go(tx, ty, k, tx, ty, 3);
					}
					if (check(tx, ty, 4)) {
						mat[tx][ty] = 4;
						go(tx, ty, k, tx, ty, 4);
					}
					if (check(tx, ty, 7)) {
						mat[tx][ty] = 7;
						go(tx, ty, k, tx, ty, 7);
					}
					mat[tx][ty] = 0;
				}
				else if (k == 2) {
					if (check(tx, ty, 2)) {
						mat[tx][ty] = 2;
						go(tx, ty, k, tx, ty, 2);
					}
					if (check(tx, ty, 3)) {
						mat[tx][ty] = 3;
						go(tx, ty, k, tx, ty, 3);
					}
					if (check(tx, ty, 6)) {
						mat[tx][ty] = 6;
						go(tx, ty, k, tx, ty, 6);
					}
					if (check(tx, ty, 7)) {
						mat[tx][ty] = 7;
						go(tx, ty, k, tx, ty, 7);
					}
					mat[tx][ty] = 0;
				}
				else if (k == 3) {
					if (check(tx, ty, 2)) {
						mat[tx][ty] = 2;
						go(tx, ty, k, tx, ty, 2);
					}
					if (check(tx, ty, 3)) {
						mat[tx][ty] = 3;
						go(tx, ty, k, tx, ty, 3);
					}
					if (check(tx, ty, 4)) {
						mat[tx][ty] = 4;
						go(tx, ty, k, tx, ty, 4);
					}
					if (check(tx, ty, 5)) {
						mat[tx][ty] = 5;
						go(tx, ty, k, tx, ty, 5);
					}
					mat[tx][ty] = 0;
				}
			}
		}
	}
	else {
		bool ok = false;
		if (mat[x][y] == 1) {
			int tx = x + dx[dir];
			int ty = y + dy[dir];

			if (tx >= 0 && ty >= 0 && tx < n && ty < m && mat[tx][ty] != 0) {
				ok = true;
				go(tx, ty, dir, px, py, kind);
			}
		}
		else if (mat[x][y] == 2) {
			int tx = x + dx[dir];
			int ty = y + dy[dir];

			if (tx >= 0 && ty >= 0 && tx < n && ty < m && mat[tx][ty] != 0) {
				ok = true;
				go(tx, ty, dir, px, py, kind);
			}
		}
		else if (mat[x][y] == 3) {
			int tx = x + dx[dir];
			int ty = y + dy[dir];

			if (tx >= 0 && ty >= 0 && tx < n && ty < m && mat[tx][ty] != 0) {
				ok = true;
				go(tx, ty, dir, px, py, kind);
			}
		}
		else if (mat[x][y] == 4) {
			if (dir == 3) dir = 0;
			else if (dir == 1) dir = 2;
			
			int tx = x + dx[dir];
			int ty = y + dy[dir];
			
			if (tx >= 0 && ty >= 0 && tx < n && ty < m && mat[tx][ty] != 0) {
				ok = true;
				go(tx, ty, dir, px, py, kind);
			}
		}	
		else if (mat[x][y] == 5) {
			if (dir == 0) dir = 2;
			else if (dir == 3) dir = 1;

			int tx = x + dx[dir];
			int ty = y + dy[dir];

			if (tx >= 0 && ty >= 0 && tx < n && ty < m && mat[tx][ty] != 0) {
				ok = true;
				go(tx, ty, dir, px, py, kind);
			}
		}
		else if (mat[x][y] == 6) {
			if (dir == 2) dir = 1;
			else if (dir == 0) dir = 3;

			int tx = x + dx[dir];
			int ty = y + dy[dir];

			if (tx >= 0 && ty >= 0 && tx < n && ty < m && mat[tx][ty] != 0) {
				ok = true;
				go(tx, ty, dir, px, py, kind);
			}
		}
		else if (mat[x][y] == 7) {
			if (dir == 2) dir = 0;
			else if (dir == 1) dir = 3;
			
			int tx = x + dx[dir];
			int ty = y + dy[dir];
			
			if (tx >= 0 && ty >= 0 && tx < n && ty < m && mat[tx][ty] != 0) {
				ok = true;
				go(tx, ty, dir, px, py, kind);
			}
		}
		
		if (!ok && kind == -1 && mat[x][y] != 8) {
			int tx = x + dx[dir];
			int ty = y + dy[dir];

			if (tx >= 0 && ty >= 0 && tx < n && ty < m) {
				if (dir == 0) {
					if (check(tx, ty, 1)) {
						mat[tx][ty] = 1;
						go(tx, ty, dir, tx, ty, 1);
					}
					if (check(tx, ty, 3)) {
						mat[tx][ty] = 3;
						go(tx, ty, dir, tx, ty, 3);
					}
					if (check(tx, ty, 5)) {
						mat[tx][ty] = 5;
						go(tx, ty, dir, tx, ty, 5);
					}
					if (check(tx, ty, 6)) {
						mat[tx][ty] = 6;
						go(tx, ty, dir, tx, ty, 6);
					}
					mat[tx][ty] = 0;
				}
				else if (dir == 1) {
					if (check(tx, ty, 1)) {
						mat[tx][ty] = 1;
						go(tx, ty, dir, tx, ty, 1);
					}
					if (check(tx, ty, 3)) {
						mat[tx][ty] = 3;
						go(tx, ty, dir, tx, ty, 3);
					}
					if (check(tx, ty, 4)) {
						mat[tx][ty] = 4;
						go(tx, ty, dir, tx, ty, 4);
					}
					if (check(tx, ty, 7)) {
						mat[tx][ty] = 7;
						go(tx, ty, dir, tx, ty, 7);
					}
					mat[tx][ty] = 0;
				}
				else if (dir == 2) {
					if (check(tx, ty, 2)) {
						mat[tx][ty] = 2;
						go(tx, ty, dir, tx, ty, 2);
					}
					if (check(tx, ty, 3)) {
						mat[tx][ty] = 3;
						go(tx, ty, dir, tx, ty, 3);
					}
					if (check(tx, ty, 6)) {
						mat[tx][ty] = 6;
						go(tx, ty, dir, tx, ty, 6);
					}
					if (check(tx, ty, 7)) {
						mat[tx][ty] = 7;
						go(tx, ty, dir, tx, ty, 7);
					}
					mat[tx][ty] = 0;
				}
				else if (dir == 3) {
					if (check(tx, ty, 2)) {
						mat[tx][ty] = 2;
						go(tx, ty, dir, tx, ty, 2);
					}
					if (check(tx, ty, 3)) {
						mat[tx][ty] = 3;
						go(tx, ty, dir, tx, ty, 3);
					}
					if (check(tx, ty, 4)) {
						mat[tx][ty] = 4;
						go(tx, ty, dir, tx, ty, 4);
					}
					if (check(tx, ty, 5)) {
						mat[tx][ty] = 5;
						go(tx, ty, dir, tx, ty, 5);
					}
					mat[tx][ty] = 0;
				}
			}
		}
	}

	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int sx, sy;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '|') mat[i][j] = 1;
			else if (s[j] == '-') mat[i][j] = 2;
			else if (s[j] == '+') mat[i][j] = 3;
			else if (s[j] == '1') mat[i][j] = 4;
			else if (s[j] == '2') mat[i][j] = 5;
			else if (s[j] == '3') mat[i][j] = 6;	
			else if (s[j] == '4') mat[i][j] = 7;
			else if (s[j] == 'M') { mat[i][j] = 8; sx = i, sy = j; }
			else if (s[j] == 'Z') { mat[i][j] = 9; ex = i, ey = j; }
		}
	}
	
	go(sx, sy, -1, -1, -1, -1);
	return 0;
}
