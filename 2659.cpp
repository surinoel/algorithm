#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool check[10000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	deque<int> dq(4);
	for (int i = 0; i < 4; i++) {
		cin >> dq[i];
	}
	int ans = -1;
	for (int i = 0; i < 4; i++) {
		int val = 0;
		for (int j = 0; j < 4; j++) {
			val = val * 10 + dq[j];
		}
		if (ans == -1 || ans > val) {
			ans = val;
		}
		int dqf = dq.front();
		dq.pop_front();
		dq.push_back(dqf);
	}

	vector<int> list;
	for (int i = 1111; i <= 9999; i++) {
		if (check[i]) continue;
		string s = to_string(i);
		dq.clear();
		bool ok = true;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '0') {
				ok = false;
				break;
			}
			dq.push_back(s[j] - '0');
		}
		if (!ok) continue;
		
		ok = true;
		int tmax = -1;
		for (int j = 0; j < 4; j++) {
			int val = 0;
			for (int k = 0; k < 4; k++) {
				val = val * 10 + dq[k];
			}
			check[val] = true;
			if (tmax == -1 || tmax > val) {
				tmax = val;
			}
			int dqf = dq.front();
			dq.pop_front();
			dq.push_back(dqf);
		}
		list.push_back(tmax);
	}
	
	sort(list.begin(), list.end());
	for (int i = 0; i < list.size(); i++) {
		if (list[i] == ans) {
			cout << i + 1 << '\n';
			return 0;
		}
	}
}
