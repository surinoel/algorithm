#include <queue>
#include <iostream>

using namespace std;

int sdist[21][21];
int dist[21][21];
bool check[21][21];
bool visit[21];

struct edge {
	int from, to, cost;
	edge() {}
	edge(int from, int to, int cost) :
		from(from), to(to), cost(cost) {

	}
};

struct cmp {
	bool operator()(const edge& u, const edge& v) {
		return u.cost > v.cost;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int inf = 1e8;
	priority_queue < edge, vector<edge>, cmp> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> sdist[i][j];
			if (i != j && !check[i][j] && !check[j][i]) {
				check[i][j] = check[j][i] = true;
				q.push(edge(i, j, sdist[i][j]));
			}
			if (i != j) dist[i][j] = inf;
		}
	}
	
	int ans = 0;
	while (!q.empty()) {
		edge edg;
		edg = q.top();
		q.pop();

		int from = edg.from;
		int to = edg.to;
		int cost = edg.cost;
		if (visit[from] == false || visit[to] == false) {
			visit[from] = visit[to] = true;
			ans += cost;
			dist[from][to] = dist[to][from] = cost;
		}
		else {
			bool ok = false;
			for (int k = 1; k <= n; k++) {
				if (dist[from][k] != inf && dist[k][to] != inf &&
					dist[from][k] + dist[k][to] == cost) {
					ok = true;
					break;
				}
				else if (dist[from][k] != inf && dist[k][to] != inf &&
					dist[from][k] + dist[k][to] < cost) {
					cout << -1 << '\n';
					return 0;
				}
			}
			if (!ok) {
				ans += cost;
			}
			dist[from][to] = dist[to][from] = cost;
		}
	}

	cout << ans << '\n';
	return 0;
}
