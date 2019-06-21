#include <tuple>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

struct edge {
	int to, cost;
	edge(int to, int cost) : to(to), cost(cost) {}
};

vector<edge> a[1001];
bool check[1001];
int dist[1001];
int from[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; 
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		a[x].push_back(edge(y, d));
	}
	int inf = 2100000000;
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}
	int st, ex;
	cin >> st >> ex;
	dist[st] = 0;
	from[st] = -1;

	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, st));

	while (!q.empty()) {
		int cost, node;
		tie(cost, node) = q.top();
		q.pop();

		if (check[node]) continue;
		check[node] = true;
		for (int i = 0; i < a[node].size(); i++) {
			int y = a[node][i].to;
			if (dist[y] > dist[node] + a[node][i].cost) {
				dist[y] = dist[node] + a[node][i].cost;
				q.push(make_pair(-dist[y], y));
				from[y] = node;
			}
		}
	}

	cout << dist[ex] << '\n';
	int idx = ex;
	stack<int> s;
	while (from[idx] != -1) {
		s.push(idx);
		idx = from[idx];
	}
	s.push(idx);
	cout << s.size() << '\n';
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';

	return 0;
}
