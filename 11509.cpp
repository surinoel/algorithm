#include <cstdio>

int arrow[1000001];

int main(void) {
	int n; scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int m; scanf("%d", &m);
		if (arrow[m] == 0) {
			cnt++;
			arrow[m - 1]++;
		}
		else if(arrow[m] > 0) {
			arrow[m]--;
			arrow[m - 1]++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
