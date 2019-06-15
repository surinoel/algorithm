#include <tuple>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct edge {
	int x, d;
	edge(int _x, int _d) : x(_x), d(_d) {}
};

struct cmp {
	bool operator()(const edge &u, const edge &v) {
		return u.d > v.d;
	}
};

vector<pair<int, int>> graph[100001];
bool visit[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		graph[x].push_back(make_pair(y, d));
		graph[y].push_back(make_pair(x, d));
	}

	priority_queue<edge, vector<edge>, cmp> q;
	for (int i = 0; i < graph[1].size(); i++) {
		q.push(edge(graph[1][i].first, graph[1][i].second));
	}
	visit[1] = true;

	int cost = 0;
	int maxv = -1;
	while (!q.empty()) {
		edge node = q.top();
		q.pop();
		
		if (visit[node.x]) continue;
		visit[node.x] = true;
		cost += node.d;
		if (maxv == -1 || node.d > maxv) {
			maxv = node.d;
		}
		for (int k = 0; k < graph[node.x].size(); k++) {
			q.push(edge(graph[node.x][k].first, graph[node.x][k].second));
		}
		
	}

	cout << cost - maxv << '\n';
	return 0;
}
