#include <iostream>

using namespace std;

int d[10000][4];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	d[1][1] = d[2][2] = d[3][3] = 1;
	for (int i = 1; i <= 10000; i++) {
		if (i - 1 >= 1) {
			d[i][1] = d[i - 1][1];
		}
		if (i - 2 >= 1) {
			d[i][2] = d[i - 2][1] + d[i - 2][2];
		}
		if (i - 3 >= 1) {
			d[i][3] = d[i - 3][1] + d[i - 3][2] + d[i - 3][3];
		}
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		cout << d[n][1] + d[n][2] + d[n][3] << '\n';
	}
	
	return 0;
}
