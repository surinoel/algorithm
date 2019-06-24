#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> mat[101];
bool visit[101];

void go(int idx, int p, bool &cycle) {
	if (visit[idx] && idx == p) {
		cycle = true;
		return;
	}
	if (visit[idx]) return;

	visit[idx] = true;
	for (int i = 0; i < mat[idx].size(); i++) {
		go(mat[idx][i], p, cycle);
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x; cin >> x;
			if (x == 1) {
				mat[i].push_back(j);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		bool ok = false;
		go(i, i, ok);
		if (!ok) visit[i] = false;
		for (int j = 1; j <= n; j++) {
			if (visit[j]) cout << 1 << ' ';
			else cout << 0 << ' ';
		}
		cout << '\n';
	}

	return 0;
}
