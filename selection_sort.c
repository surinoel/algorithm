#include <stdio.h>

int main(void) {
	int n = 5;
	int a[5] = { 5, 4, 3, 2, 1 };

	for (int i = 0; i < n - 1; i++) {
		int idx, val;
		idx = i, val = a[i];
		for (int j = i + 1; j < n; j++) {
			if (val > a[j]) {
				val = a[j];
				idx = j;
			}
		}
		int tmp = a[i];
		a[i] = a[idx];
		a[idx] = tmp;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
