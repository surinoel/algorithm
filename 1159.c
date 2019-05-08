#include <stdio.h>

char buf[256];
int alpha[26];

int main(void) {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", buf);
		alpha[buf[0] - 'a'] += 1;
	}
	bool ok = false;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] >= 5) {
			ok = true;
			printf("%c", 'a' + i);
		}
	}

	if (!ok) printf("PREDAJA\n");
	else printf("\n");
	return 0;
}
