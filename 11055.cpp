#include <iostream>

using namespace std;

int a[1000];
int s[1000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s[i] = a[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && s[i] < s[j] + a[i]) {
				s[i] = s[j] + a[i];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] > ans) {
			ans = s[i];
		}
	}
	cout << ans << '\n';
	return 0;
}