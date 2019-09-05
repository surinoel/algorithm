#include <vector>
#include <iostream>

using namespace std;

bool visit[1001];
vector<int> a[1001];

void go(int idx) {
	if (visit[idx]) {
		return;
	}
	visit[idx] = true;
	for (int i = 0; i < a[idx].size(); i++) {
		go(a[idx][i]);
	}
	return;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			ans += 1;
			go(i);
		}
	}
		
	cout << ans << '\n';
	return 0;
}
