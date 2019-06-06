#include <iomanip>
#include <iostream>

using namespace std;

double memo[51];

double fact(int n) {
	if (n == 1 || n == 0) return 1;
	if (memo[n] > 0) {
		return memo[n];
	}
	return memo[n] = n * fact(n - 1);
}

double comb(int n, int r) {
	double a, b, c;
	a = fact(n);
	b = fact(r);
	c = fact(n - r);

	return a / (b*c);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m, r;
	cin >> n >> m;
	r = m - n;
	cout << fixed << setprecision(0) << comb(n + r - 1, r) << '\n';
	return 0;
}

#if 0
#include <iostream>

using namespace std;

int n, m;
int ans;

void go(int kind, int cnt) {
	if (cnt == m - n) {
		ans += 1;
		return;
	}
	if (kind == n || cnt > m - n) {
		return;
	}

	for (int i = 0; i <= m - n; i++) {
		go(kind + 1, cnt + i);
	}

	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i <= m - n; i++) {
		go(1, i);
	}

	cout << ans << '\n';
	return 0;
}
#endif
