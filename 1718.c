#include <stdio.h>
#include <string.h>

char buf[30002], key[30001];

int main(void) {
	fgets(buf, sizeof(buf), stdin);
	scanf("%s", key);

	int idx = -1;
	int len = strlen(key);
	for (int i = 0; buf[i] != '\n'; i++) {
		if (++idx == len) idx = 0;
		if (buf[i] == 32) {
			printf(" ");
			continue;
		}
		int n = key[idx];
		int k = buf[i];
		if (k - n < 0) k += 26;
		if (k - n == 0) buf[i] = 'z';
		else buf[i] = k - n + 'a' - 1;
		printf("%c", buf[i]);
	}
	printf("\n");
	return 0;
}
