#include <stdio.h>
#include <string.h>

int a[150];
int visit[150];

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	memset(visit, 0, sizeof(visit));
	visit[0] = 1;
	int next = a[0];
	int k = 1;
	for (;;) {
		if (visit[next]) {
			printf("-1\n");
			return 0;
		}
		else {
			if (next == m) {
				printf("%d\n", k);
				return 0;
			}
			visit[next] = 1;
			next = a[next];
		}
		k++;
	}

	return 0;
}
