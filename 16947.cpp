#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<int> mat[3001];
int check[3001];
int dist[3001];

int go(int x, int p) {
	if (check[x]) {
		return x;
	}

	check[x] = 1;
	for (int k = 0; k < mat[x].size(); k++) {
		int y = mat[x][k];
		if (y == p) continue;
		int ret = go(y, x);
		if (ret == -2) return -2;
		if (ret >= 0) {
			check[x] = 2;
			if (ret == x) return -2;
			else return ret;
		}
	}
	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		mat[x].push_back(y);
		mat[y].push_back(x);
	}

	go(1, -1);
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (check[i] == 2) {
			dist[i] = 0;
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < mat[x].size(); i++) {
			int y = mat[x][i];
			if (check[y] == 2) continue;
			check[y] = 2;
			dist[y] = dist[x] + 1;
			q.push(y);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dist[i] << ' ';
	}
	cout << '\n';

	return 0;
}
