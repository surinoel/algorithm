#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m
#define min(n, m) n > m ? m : n

int a[100001];
int p[100001];

int Find(int x) {
	if (p[x] == x) return x;
	return p[x] = Find(p[x]);
}

int Union(int x, int y) {
	int px = Find(x);
	int py = Find(y);

	if (px < py) {
		p[py] = px;
		a[px] += a[py];
		return a[px];
	}
	else if (px > py) {
		p[px] = py;
		a[py] += a[px];
		return a[py];
	}
	else {
		return a[px];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << Union(x, y) << '\n';
	}

	return 0;
}
