#include <cstring>
#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m
#define min(n, m) n > m ? m : n

int mat[1000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int tc = 1; tc <= 10; tc++) {
		memset(mat, 0, sizeof(mat));
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> mat[j];
		}

		int ans = 0;
		for (int j = 0; j < n; j++) {
			int minleft = 0, minright = 0;
			if (j - 2 >= 0) {
				minleft = max(minleft, mat[j - 2]);
			}
			if (j - 1 >= 0) {
				minleft = max(minleft, mat[j - 1]);
			}
			if (j + 1 < n) {
				minright = max(minright, mat[j + 1]);
			}
			if (j + 2 < n) {
				minright = max(minright, mat[j + 2]);
			}
			int maxheight = max(minleft, minright);
			if (mat[j] > maxheight) {
				ans += mat[j] - maxheight;
			}
		}

		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}
