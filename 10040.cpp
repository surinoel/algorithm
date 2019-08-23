#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define max(n, m) n > m ? n : m

int game[1001];
int ans[1001];

bool cmp(const pair<int, int> &u, const pair<int, int> &v) {
	if (u.second == v.second) {
		return u.first < v.first;
	}
	return u.second < v.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> play(n);
	for (int i = 0; i < n; i++) {
		int price;
		cin >> price;
		play[i] = make_pair(i, price);
	}

	sort(play.begin(), play.end(), cmp);
	int stprice = play.begin()->second;
	int endprice = (play.end() - 1)->second;
	int idx = 0;
	int funny = play[idx].first;
	for (int i = stprice; i <= endprice; i++) {
		while (idx < n - 1 && i == play[idx + 1].second) {
			if (funny > play[idx + 1].first) {
				funny = play[idx + 1].first;
			}
			idx += 1;
		}
		game[i] = funny;
	}

	for (int i = 0; i < m; i++) {
		int g;
		cin >> g;
		ans[game[g]] += 1;
	}

	int maxv = -1;
	int maxcnt = -1;
	for (int i = 0; i < n; i++) {
		if (ans[i] > maxcnt) {
			maxcnt = ans[i];
			maxv = i;
		}
	}
	
	cout << maxv + 1 << '\n';
	return 0;
}
