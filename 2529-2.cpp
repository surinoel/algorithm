#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int n;
vector<char> vc;
bool visit[10];

int go1(int cnt, vector<int> v) {
	if (cnt == n) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
		cout << '\n';
		return 1;
	}

	for (int i = 0; i <= 9; i++) {
		if (cnt == -1) {
			visit[i] = true;
			v.push_back(i);
			if (go1(0, v)) return 1;
			v.pop_back();
			visit[i] = false;
		}
		else {
			if (!visit[i]) {
				if (vc[cnt] == '<') {
					if (v.back() < i) {
						visit[i] = true;
						v.push_back(i);
						if (go1(cnt + 1, v)) return 1;
						v.pop_back();
						visit[i] = false;
					}
				}
				else {
					if (v.back() > i) {
						visit[i] = true;
						v.push_back(i);
						if (go1(cnt + 1, v)) return 1;
						v.pop_back();
						visit[i] = false;
					}
				}
			}
		}
	}
	return 0;
}

int go2(int cnt, vector<int> v) {
	if (cnt == n) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
		cout << '\n';
		return 1;
	}

	for (int i = 9; i >= 0; i--) {
		if (cnt == -1) {
			visit[i] = true;
			v.push_back(i);
			if (go2(0, v)) return 1;
			v.pop_back();
			visit[i] = false;
		}
		else {
			if (!visit[i]) {
				if (vc[cnt] == '<') {
					if (v.back() < i) {
						visit[i] = true;
						v.push_back(i);
						if (go2(cnt + 1, v)) return 1;
						v.pop_back();
						visit[i] = false;
					}
				}
				else {
					if (v.back() > i) {
						visit[i] = true;
						v.push_back(i);
						if (go2(cnt + 1, v)) return 1;
						v.pop_back();
						visit[i] = false;
					}
				}
			}
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
	go2(-1, vector<int>());
	memset(visit, false, sizeof(visit));
	go1(-1, vector<int>());
	return 0;
}
