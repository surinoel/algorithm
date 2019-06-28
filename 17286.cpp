#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct point {
	int x, y;
	point() {}
	point(int x, int y) : x(x), y(y) {}
};

point a[4];
double d[4][4];
vector<int> pm;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 4; i++) {
		cin >> a[i].x >> a[i].y;
	}
	for (int i = 0; i < 4; i++) {
		int x1, y1;
		x1 = a[i].x, y1 = a[i].y;
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			int x2, y2;
			x2 = a[j].x, y2 = a[j].y;
			double dist;
			dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
			d[i][j] = d[j][i] = dist;
		}
	}

	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	double ans = -1;
	pm = { 0, 1, 2, 3 };
	do {
		double sum = 0;
		int st = pm[0];
		for (int i = 1; i < 4; i++) {
			sum += d[st][pm[i]];
			st = pm[i];
		}
		if (ans == -1 || ans > sum) {
			ans = sum;
		}
	} while (next_permutation(pm.begin() + 1, pm.end()));

	cout << (int)ans << '\n';
	return 0;
}
