#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int n;
vector<char> vc;
bool visit[10];

int go1(int cnt, vector<int> v) {
	if (cnt == n + 1) {
		int st = v[0];
		for (int i = 0; i < n; i++) {
			int cmp = v[i + 1];
			if (vc[i] == '<') {
				if (st > cmp) {
					return 0;
				}
			}
			else {
				if (st < cmp) {
					return 0;
				}
			}
			st = cmp;
		}
		for (int i = 0; i < n + 1; i++) {
			cout << v[i];
		}
		cout << '\n';
		return 1;
	}

	for (int i = 0; i < 10; i++) {
		if (!visit[i]) {
			visit[i] = true;
			v.push_back(i);
			if (go1(cnt + 1, v)) return 1;
			v.pop_back();
			visit[i] = false;
		}
	}
	return 0;
}

int go2(int cnt, vector<int> v) {
	if (cnt == n + 1) {
		int st = v[0];
		for (int i = 0; i < n; i++) {
			int cmp = v[i + 1];
			if (vc[i] == '<') {
				if (st > cmp) {
					return 0;
				}
			}
			else {
				if (st < cmp) {
					return 0;
				}
			}
			st = cmp;
		}
		for (int i = 0; i < n + 1; i++) {
			cout << v[i];
		}
		cout << '\n';
		return 1;
	}

	for (int i = 9; i >= 0; i--) {
		if (!visit[i]) {
			visit[i] = true;
			v.push_back(i);
			if (go2(cnt + 1, v)) return 1;
			v.pop_back();
			visit[i] = false;
		}
	}
	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vc.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> vc[i];
	}

	memset(visit, false, sizeof(visit));
	go2(0, vector<int>());
	memset(visit, false, sizeof(visit));
	go1(0, vector<int>());
	return 0;
}
