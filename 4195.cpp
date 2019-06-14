#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int p[200001];
int b[200001];
char s1[21], s2[21];

int Find(int x) {
	if (p[x] == x) return x;
	else return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	int px = Find(x);
	int py = Find(y);
	p[py] = px;
	b[px] += b[py];
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		memset(p, 0, sizeof(p));
		int n; scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++) {
			p[i] = i;
		}
		map<string, int> m;
		int idx = 1;
		for (int i = 0; i < n; i++) {
			scanf("%s %s", s1, s2);
			if (!m.count(s1)) {
				m[s1] = idx;
				b[idx++] = 1;
			}
			if (!m.count(s2)) {
				m[s2] = idx;
				b[idx++] = 1;
			}

			int ps1 = Find(m[s1]);
			int ps2 = Find(m[s2]);
			if (ps1 != ps2) {
				Union(m[s1], m[s2]);
			}

			printf("%d\n", b[ps1]);
		}
	}

	return 0;
}
