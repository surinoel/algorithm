#include <cstring>
#include <iostream>

using namespace std;

int a[200][3];
int d[101];
int ans[200];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	for (int i = 0; i < 3; i++) {
		memset(d, 0, sizeof(d));
		for (int j = 0; j < n; j++) {
			d[a[j][i]] += 1;
		}
		for (int j = 0; j < n; j++) {
			if (d[a[j][i]] == 1) {
				ans[j] += a[j][i];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}
