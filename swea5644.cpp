#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

typedef struct __bt {
	int x, y, range, power;
	__bt() : x(0), y(0), range(0), power(0) {}
	__bt(int x, int y, int range, int power) :
		x(x), y(y), range(range), power(power) {}
} BT;

int a[101], b[101];
BT bt[10];
bool btcheck[10];

int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };

bool cmp(const pair<int, int>& u, const pair<int, int>& v) {
	return u.first > v.first;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	for (int test_case = 1; test_case <= tc; test_case++) {
		vector<vector<vector<pair<int,int>>>> mat(11, vector<vector<pair<int,int>>>(11, vector<pair<int,int>>()));
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {	
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> bt[i].y >> bt[i].x >> bt[i].range >> bt[i].power;
			
			for (int u = 1; u <= 10; u++) {
				for (int v = 1; v <= 10; v++) {
					if (abs(u - bt[i].x) + abs(v - bt[i].y) <= bt[i].range) {
						mat[u][v].push_back(make_pair(bt[i].power, i));
					}
				}
			}
		}

		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				sort(mat[i][j].begin(), mat[i][j].end(), cmp);
			}
		}

		int sum = 0;
		int ax, ay, bx, by;
		ax = ay = 1;
		bx = by = 10;
		for (int i = 0; i <= n; i++) {
			ax += dx[a[i]];
			ay += dy[a[i]];
			bx += dx[b[i]];
			by += dy[b[i]];

			if (ax == bx && ay == by) {
				if (mat[ax][ay].size() == 1) {
					sum += mat[ax][ay][0].first;
				}
				else if (mat[ax][ay].size() > 1) {
					sum += mat[ax][ay][0].first;
					sum += mat[ax][ay][1].first;			
				}
			}
			else {
				int val1, val2;
				val1 = val2 = 0;
				memset(btcheck, false, sizeof(btcheck));
				if (!mat[ax][ay].empty()) {
					val1 += mat[ax][ay][0].first;
					btcheck[mat[ax][ay][0].second] = true;
				}
				if (!mat[bx][by].empty()) {
					for (int j = 0; j < mat[bx][by].size(); j++) {
						if (!btcheck[mat[bx][by][j].second]) {
							val1 += mat[bx][by][j].first;
							break;
						}
					}
					
				}
				memset(btcheck, false, sizeof(btcheck));				
				if (!mat[bx][by].empty()) {
					val2 += mat[bx][by][0].first;
					btcheck[mat[bx][by][0].second] = true;
				}
				if (!mat[ax][ay].empty()) {
					for (int j = 0; j < mat[ax][ay].size(); j++) {
						if (!btcheck[mat[ax][ay][j].second]) {
							val2 += mat[ax][ay][j].first;
							break;
						}
					}
				}
				sum += max(val1, val2);
			}
		}
		cout << "#" << test_case << " " << sum << '\n';
	}

	return 0;
}
