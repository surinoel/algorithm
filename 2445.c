#include <stdio.h>

#define max(a, b) a > b ? a : b

int main(void) {
	int n = 4;
	int ans = -1;
	int total = 0;
	while (n--) {
		int x, y; 
		scanf("%d %d", &x, &y);
		total += y - x;
		ans = max(ans, total);
	}
	printf("%d\n", ans);
	return 0;
}
