#include <deque>
#include <tuple>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool check[101];

bool cmp(const tuple<int, int, int> &u, const tuple<int, int, int> &v) {
	if (get<2>(u) == get<2>(v)) {
		return get<0>(u) > get<0>(v);
	}
	return get<2>(u) > get<2>(v);
}

bool cmp2(const tuple<int, int, int> &u, const tuple<int, int, int> &v) {
	return get<1>(u) < get<1>(v);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(check, false, sizeof(check));
	int n, m;
	cin >> n >> m;
	deque<tuple<int, int, int>> dq;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (check[num]) {
			for (int j = 0; j < dq.size(); j++) {
				if (get<1>(dq[j]) == num) {
					get<2>(dq[j]) += 1;
					break;
				}
			}
		}
		else {
			check[num] = true;
			if (dq.size() == n) {
				sort(dq.begin(), dq.end(), cmp);
				check[get<1>(dq.back())] = false;
				dq.pop_back();
				dq.push_back(make_tuple(i, num, 1));
			}
			else {
				dq.push_back(make_tuple(i, num, 1));
			}
		}
	}

	sort(dq.begin(), dq.end(), cmp2);
	for (int i = 0; i < dq.size(); i++) {
		cout << get<1>(dq[i]) << ' ';
	}
  
	cout << '\n';
	return 0;
}
