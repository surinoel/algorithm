#include <vector>
#include <iostream>

using namespace std;

vector<int> a[101];
bool visit[101];

void go(int idx) {
	if (visit[idx]) return;
	visit[idx] = true;

	for (int i = 0; i < a[idx].size(); i++) {
		go(a[idx][i]);
	}
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
	
	go(1);
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (visit[i]) cnt += 1;
	}

	cout << cnt << '\n';
	return 0;
}
