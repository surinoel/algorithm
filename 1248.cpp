#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
vector<char> vc;

struct Base {
	int x, y;
	char ch;
	Base(int x, int y, int ch) : x(x), y(y), ch(ch) {

	}
};

vector<Base> base;
void go1(int idx, vector<int> v) {
	if (v.size() == 2) {
		base.push_back(Base(v[0], v[1], '0'));
		return;
	}

	for (int i = idx; i < n; i++) {
		v.push_back(i);
		go1(i, v);
		v.pop_back();
	}
}

void go(int idx, int cnt, vector<int> v) {
	if (idx == n) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		exit(0);
	}

	for (int i = -10; i <= 10; i++) {
		v.push_back(i);
		bool ok = true;
		for (int j = cnt; j <= cnt + idx; j++) {
			int tsum = 0;
			for (int k = base[j].x; k <= base[j].y; k++) {
				tsum += v[k];
			}
			if (tsum > 0 && base[j].ch == '+') {
				ok = true;
			}
			else if (tsum == 0 && base[j].ch == '0') {
				ok = true;
			}
			else if (tsum < 0 && base[j].ch == '-') {
				ok = true;
			}
			else {
				ok = false;
				break;
			}
		}
		if (ok) {
			go(idx + 1, cnt + idx + 1, v);
		}
		v.pop_back();
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	go1(0, vector<int>());
	
	vc.resize(n*(n + 1) / 2);
	for (int i = 0; i < n*(n + 1) / 2; i++) {
		cin >> base[i].ch;
	}

	sort(base.begin(), base.end(), [](const Base &u, const Base &v) {
		if (u.y == v.y) {
			return u.x < v.x;
		}
		return u.y < v.y;
	});
	
	go(0, 0, vector<int>());
	return 0;
}
