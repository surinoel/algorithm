#include <stdio.h>
#include <string.h>

char buf1[10002], buf2[10002], cbuf1[10002], cbuf2[10002];
char ans[10003];

int main(void) {
	scanf("%s %s", buf1, buf2);
	if (strlen(buf1) > strlen(buf2)) {
		memcpy(cbuf1, buf1, sizeof(buf1));
		for (int i = 0; i < strlen(buf1); i++) {
			if (i < strlen(buf1) - strlen(buf2)) {
				cbuf2[i] = '0';
			}
			else {
				cbuf2[i] = buf2[i - (strlen(buf1) - strlen(buf2))];
			}
		}
	}
	else if (strlen(buf1) < strlen(buf2)) {
		memcpy(cbuf2, buf2, sizeof(buf2));
		for (int i = 0; i < strlen(buf2); i++) {
			if (i < strlen(buf2) - strlen(buf1)) {
				cbuf1[i] = '0';
			}
			else {
				cbuf1[i] = buf1[i - (strlen(buf2) - strlen(buf1))];
			}
		}
	}
	else {
		memcpy(cbuf1, buf1, sizeof(buf1));
		memcpy(cbuf2, buf2, sizeof(buf2));
	}

	int carry = 0;
	for (int i = strlen(cbuf1) - 1; i >= 0; i--) {
		int sum = cbuf1[i] + cbuf2[i] + carry - '0' * 2;
		carry = sum / 10;
		ans[i] = sum % 10 + '0';
	}
	if (carry) {
		printf("1");
	}
	for (int i = 0; i < strlen(ans); i++) {
		printf("%c", ans[i]);
	}
	printf("\n");
	return 0;
}
