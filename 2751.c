#include <stdio.h>

int arr[1000000];

int main(void) {
	int len;
	scanf("%d", &len);
	for (int i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < len; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}
