#include <iostream>
#include <cstring>

using namespace std;

int a[1000];
int d[1000];
int v[1000];

void go(int idx) {
	if (idx == -1) {
		return;
	}

	go(v[idx]);
	cout << a[idx] << ' ';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(v, -1, sizeof(v));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}

	int ans = 0;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] > ans) {
			ans = d[i];
			idx = i;
		}
	}
	cout << ans << '\n';
	go(idx);
	cout << '\n';

	return 0;
}