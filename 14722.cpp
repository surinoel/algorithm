#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int mat[1000][1000];
int d[1000][1000][3];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			d[i][j][1] = -1;
			d[i][j][2] = -1;
			d[i][j][0] = (mat[i][j] == 0) ? 1 : -1;
		}
	}

	for (int j = 1; j < n; j++) {
		if (mat[0][j] == 0) {
			if (d[0][j - 1][2] != -1) d[0][j][0] = d[0][j - 1][2] + 1;
			d[0][j][1] = d[0][j - 1][1];
			d[0][j][2] = d[0][j - 1][2];
		}
		else if (mat[0][j] == 1) {
			if (d[0][j - 1][0] != -1) d[0][j][1] = d[0][j - 1][0] + 1;
			d[0][j][0] = d[0][j - 1][0];
			d[0][j][2] = d[0][j - 1][2];
		}
		else {
			if (d[0][j - 1][1] != -1) d[0][j][2] = d[0][j - 1][1] + 1;
			d[0][j][0] = d[0][j - 1][0];
			d[0][j][1] = d[0][j - 1][1];
		}
	}

	for (int i = 1; i < n; i++) {
		if (mat[i][0] == 0) {
			if (d[i - 1][0][2] != -1) d[i][0][0] = d[i - 1][0][2] + 1;
			d[i][0][1] = d[i - 1][0][1];
			d[i][0][2] = d[i - 1][0][2];
		}
		else if (mat[i][0] == 1) {
			if (d[i - 1][0][0] != -1) d[i][0][1] = d[i - 1][0][0] + 1;
			d[i][0][0] = d[i - 1][0][0];
			d[i][0][2] = d[i - 1][0][2];
		}
		else {
			if (d[i - 1][0][1] != -1) d[i][0][2] = d[i - 1][0][1] + 1;
			d[i][0][0] = d[i - 1][0][0];
			d[i][0][1] = d[i - 1][0][1];
		}
	}
	
	int ans = -1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (mat[i][j] == 0) {
				if (d[i - 1][j][2] != -1) d[i][j][0] = d[i - 1][j][2] + 1;
				if (d[i][j - 1][2] != -1) d[i][j][0] = max(d[i][j][0], d[i][j - 1][2] + 1);
				d[i][j][1] = max(d[i - 1][j][1], d[i][j - 1][1]);
				d[i][j][2] = max(d[i - 1][j][2], d[i][j - 1][2]);
			}
			else if (mat[i][j] == 1) {
				if (d[i - 1][j][0] != -1) d[i][j][1] = d[i - 1][j][0] + 1;
			    if (d[i][j - 1][0] != -1) d[i][j][1] = max(d[i][j][1], d[i][j - 1][0] + 1);
				d[i][j][0] = max(d[i - 1][j][0], d[i][j - 1][0]);
				d[i][j][2] = max(d[i - 1][j][2], d[i][j - 1][2]);
			}
			else {
				if (d[i - 1][j][1] != -1) d[i][j][2] = d[i - 1][j][1] + 1;
				if (d[i][j - 1][1] != -1) d[i][j][2] = max(d[i][j][2], d[i][j - 1][1] + 1);
				d[i][j][0] = max(d[i - 1][j][0], d[i][j - 1][0]);
				d[i][j][1] = max(d[i - 1][j][1], d[i][j - 1][1]);
			}

			int mval = max(d[i][j][0], max(d[i][j][1], d[i][j][2]));
			if (ans == -1 || mval > ans) {
				ans = mval;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
