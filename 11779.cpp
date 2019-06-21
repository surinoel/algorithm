#include <stack>
#include <vector>
#include <iostream>

using namespace std;

struct edge {
	int to, cost;
	edge(int to, int cost) : to(to), cost(cost) {}
};

vector<edge> a[1001];
int dist[1001];
int from[1001];
bool check[1001];

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

	for (int i = 0; i < n - 1; i++) {
		int m, d = inf;
		for (int j = 1; j <= n; j++) {
			if (check[j] == false && d > dist[j]) {
				m = j;
				d = dist[j];
			}
		}
		check[m] = true;
		for (int j = 0; j < a[m].size(); j++) {
			int y = a[m][j].to;
			if (dist[y] > dist[m] + a[m][j].cost) {
				dist[y] = dist[m] + a[m][j].cost;
				from[y] = m;
			}
		}
	}

	cout << dist[ex] << '\n';
	stack<int> s;
	int idx = ex;
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
