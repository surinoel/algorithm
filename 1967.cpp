#include <queue>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int dist[10001];
vector<pair<int,int>> t[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		t[x].push_back(make_pair(y, d));
		t[y].push_back(make_pair(x, d));
	}

	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (auto y : t[x]) {
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
			mdist = dist[i];
			region = i;
		}
	}
	
	memset(dist, -1, sizeof(dist));
	q = queue<int>();
	q.push(region);
	dist[region] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (auto y : t[x]) {
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
