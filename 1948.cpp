#include <queue>
#include <vector>
#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m

vector<pair<int, int>> world[10001];
vector<pair<int, int>> back[10001];
int dist[10001];
int ind[10001];
bool visit[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int x, y, t;
		cin >> x >> y >> t;
		world[x].push_back(make_pair(y, t));
		back[y].push_back(make_pair(x, t));
		ind[y] += 1;
	}

	int st, ex;
	cin >> st >> ex;
	queue<int> q;
	q.push(st);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int k = 0; k < world[x].size(); k++) {
			int node = world[x][k].first;
			int dst = world[x][k].second;
			
			ind[node] -= 1;
			if (ind[node] == 0) {
				q.push(node);
			}
			dist[node] = max(dist[node], dist[x] + dst);
		}
	}

	q.push(ex);
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int k = 0; k < back[x].size(); k++) {
			int node = back[x][k].first;
			int dst = back[x][k].second;
			
			if (dst == dist[x] - dist[node]) {
				cnt += 1;
				if (!visit[node]) {
					visit[node] = true;
					q.push(node);
				}
			}
		}
	}

	cout << dist[ex] << '\n' << cnt << '\n';
	return 0;
}
