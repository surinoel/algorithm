#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int p[10001];

int Find(int idx) {
	if (p[idx] == idx) return idx;
	else return p[idx] = Find(p[idx]);
}

void Union(int x, int y) {
	int p1 = Find(x);
	int p2 = Find(y);
	p[p2] = p1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	vector<tuple<int, int, int>> edge;
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		edge.push_back(make_tuple(x, y, d));
	}

	sort(edge.begin(), edge.end(), [](const tuple<int, int, int> &u, const tuple<int, int, int> &v) {
		return get<2>(u) < get<2>(v);
	});

	int ans = 0;
	for (int i = 0; i < edge.size(); i++) {
		int n1, n2, dist;
		tie(n1, n2, dist) = edge[i];
		if (Find(n1) != Find(n2)) {
			ans += dist;
			Union(n1, n2);
		}
	}

	cout << ans << '\n';
	return 0;
}
