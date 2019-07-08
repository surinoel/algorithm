#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<int> tree[50001];
int p[50001];
int d[50001];

void swap(int* x, int* y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int LCA(int x, int y)
{
	if (d[x] < d[y]) {
		swap(x, y);
	}
	while (d[x] != d[y]) {
		x = p[x];
	}
	while (x != y) {
		x = p[x];
		y = p[y];
	}
	return x;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	queue<int> q;
	q.push(1);
	p[1] = -1;
	d[1] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < tree[x].size(); i++) {
			int y = tree[x][i];
			if (p[y] != 0) continue;
			p[y] = x;
			d[y] = d[x] + 1;
			q.push(y);
		}
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int x, y;
		cin >> x >> y;
		cout << LCA(x, y) << '\n';
	}

	return 0;
}
