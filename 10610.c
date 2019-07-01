#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
char buf[100001];
int cnt[10];
 
int main(void) {
	scanf("%s", buf);
	int sum = 0, len = strlen(buf);
	bool ok = false;
	for (int i = 0; i < len; i++) {
		sum += buf[i] - '0';
		if (buf[i] == '0') ok = true;
		cnt[buf[i] - '0'] += 1;
	}
	if ((strlen(buf) == 1 && sum % 3 != 0) || !(strlen(buf) > 1 && ok && sum % 3 == 0)) {
		printf("-1\n");
		return 0;
	}
 
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < cnt[i]; j++) {
			printf("%d", i);
		}
	}
	printf("\n");
 
	return 0;
}
