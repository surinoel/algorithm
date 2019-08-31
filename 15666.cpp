#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
bool visit[9];
vector<int> num;
vector<vector<int>> ans;

void go(int idx, int maxcnt, vector<int> v) {
	if (maxcnt == m) {
		ans.push_back(v);
		return;
	}

	for (int i = idx; i < n; i++) {
		v.push_back(num[i]);
		go(i, maxcnt + 1, v);
		v.pop_back();
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	
	num.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	go(0, 0, vector<int>());

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
