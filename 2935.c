#include <stdio.h>
#include <string.h>

char buf1[256], buf2[256];

int main(void) {
	char op;
	scanf("%s %c %s", buf1, &op, buf2);
	
	if (op == '*') {
		int len1, len2;
		len1 = strlen(buf1) - 1;
		len2 = strlen(buf2) - 1;
		printf("1");
		for (int i = 1; i <= len1 + len2; i++) {
			printf("0");
		}
		printf("\n");
	}
	else {
		int len1 = strlen(buf1);
		int len2 = strlen(buf2);
		if (len1 > len2) {
			printf("1");
			for (int i = 1; i < len1; i++) {
				if (i == len1 - len2) printf("1");
				else printf("0");
			}
			printf("\n");
		}
		else if (len1 < len2) {
			printf("1");
			for (int i = 1; i < len2; i++) {
				if (i == len2 - len1) printf("1");
				else printf("0");
			}
			printf("\n");
		}
		else {
			printf("2");
			for (int i = 1; i < len1; i++) {
				printf("0");
			}
			printf("\n");
		}
	}

	return 0;
}
