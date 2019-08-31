#include <vector>
#include <iostream>

using namespace std;

int n, m;
bool visit[9];

void go(int idx, int maxcnt, vector<int> v) {
	if (maxcnt == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			v.push_back(i);
			go(i + 1, maxcnt + 1, v);
			v.pop_back();
			visit[i] = false;
		}
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	go(1, 0, vector<int>());
	return 0;
}
