#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
bool visit[9];
vector<int> num;

void go(int maxcnt, vector<int> v) {
	if (maxcnt == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			v.push_back(num[i]);
			go(maxcnt + 1, v);
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
	
	num.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());

	go(0, vector<int>());
	return 0;
}
