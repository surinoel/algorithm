#include <iostream>

using namespace std;

long long a[100];
long long d[100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] *= (i + 1);
	}

	d[0] = a[0];
	for (int i = 1; i < n; i++) {
		d[i] = a[i];
		for (int j = 0; j < i; j++) {
			d[i] -= d[j];
		}
	}

	for (int i = 0; i < n; i++) {
		cout << d[i] << ' ';
	}
	cout << '\n';

	return 0;
}
