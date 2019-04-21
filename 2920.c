#include <stdbool.h>
#include <stdio.h>

int arr[8];

int main(void) {
	for (int i = 0; i < 8; i++) {
		scanf("%d", &arr[i]);
	}

	bool ok = true;
	for (int i = 1; i <= 8; i++) {
		if (arr[i - 1] != i) {
			ok = false;
			break;
		}
	}
	if (ok) {
		printf("ascending\n");
		return 0;
	}
	
	ok = true;
	for (int i = 8; i >= 1; i--) {
		if (arr[8 - i] != i) {
			ok = false;
			break;
		}
	}
	if (ok) {
		printf("descending\n");
		return 0;
	}

	printf("mixed\n");
	return 0;
}
