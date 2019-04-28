#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; i*j <= n; j++) {
			ans += 1;
		}
	}
	cout << ans << '\n';
	return 0;
}

/*
#include <iostream>

using namespace std;

bool check[10001][10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += 1;
		for (int j = 2; j <= i / 2; j++) {
			if (i%j == 0 && !check[i/j][j] && !check[j][i/j]) {
				check[i/j][j] = check[j][i/j] = true;
				ans += 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
*/
