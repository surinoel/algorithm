#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, int>> t[100001];
int dist[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("data.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (;;) {
			int a, d;
			cin >> a;
			if (a == -1) break;
			cin >> d;
			t[x].push_back(make_pair(a, d));
			t[a].push_back(make_pair(x, d));
		}
	}

	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (pair<int, int> y : t[x]) {
			if (dist[y.first] == -1) {
				dist[y.first] = dist[x] + y.second;
				q.push(y.first);
			}
		}
	}

	int region;
	int mdist = -1;
	for (int i = 1; i <= n; i++) {
		if (mdist == -1 || dist[i] > mdist) {
			region = i;
			mdist = dist[i];
		}
	}

	memset(dist, -1, sizeof(dist));
	q = queue<int>();
	q.push(region);
	dist[region] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (pair<int, int> y : t[x]) {
			if (dist[y.first] == -1) {
				dist[y.first] = dist[x] + y.second;
				q.push(y.first);
			}
		}
	}

	mdist = -1;
	for (int i = 1; i <= n; i++) {
		if (mdist == -1 || dist[i] > mdist) {
			mdist = dist[i];
		}
	}

	cout << mdist << '\n';
	return 0;
}
