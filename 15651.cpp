#include <vector>
#include <iostream>

using namespace std;

int n, m;

void go(int maxcnt, vector<int> v) {
	if (maxcnt == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		go( maxcnt + 1, v);
		v.pop_back();
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	
	go(0, vector<int>());
	return 0;
}
