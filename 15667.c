#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int left = 0, right = n;
	int mid = (left + right) / 2;
	
	while (left <= right) {
		int total = 1 + mid + mid*mid;
		if (total == n) {
			printf("%d\n", mid);
			return 0;
		}
		else if (total > n) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}

		mid = (left + right) / 2;
	}

	return 0;
}
