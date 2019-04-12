#include <iostream>

using namespace std;

int d[10001];
int a[100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	d[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - a[i] >= 0) {
				d[j] += d[j - a[i]];
			}
		}
	}
	cout << d[k] << '\n';
	return 0;
}
