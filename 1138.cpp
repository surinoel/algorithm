#include <iostream>

using namespace std;

int a[11];
int b[11];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (b[j] == 0) {
				cnt += 1;
			}
			if (cnt > a[i]) {
				b[j] = i;
				break;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << b[i] << ' ';
	}
	cout << '\n';
	return 0;
}
