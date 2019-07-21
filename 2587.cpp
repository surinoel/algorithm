#include <iostream>

using namespace std;

int a[5];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
		sum += a[i];
	}

	cout << sum / 5 << '\n';
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4 - i; j++) {
			if (a[j] < a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	cout << a[2] << '\n';
	return 0;
}
