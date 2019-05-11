#include <iostream>

using namespace std;

int p[100001];
int ans[100001];
bool chk[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	while (m--) {
		int x, y; 
		cin >> x >> y;
		p[x] += 1;
		p[y] -= 1;
	}
	
	for (int i = 1; i <= n; i++) {
		if (p[i] < 1 || p[i] > n || chk[p[i]]) {
			cout << "-1\n";
			return 0;
		}
		chk[p[i]] = true;
		ans[i] = p[i];
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}
