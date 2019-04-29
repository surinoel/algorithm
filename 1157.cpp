#include <stdio.h>

int check[26];

int main(void) {
	char c;
	while (scanf("%c", &c) == 1) {
		if (c == '\0') break;
		if (c >= 'A' && c <= 'Z') {
			check[c - 'A'] += 1;
		}
		else if(c >= 'a' && c <= 'z') {
			check[c - 'a'] += 1;
		}
	}

	int idx = 0;
	int val = check[idx];
	bool ok = true;
	for (int i = 1; i < 26; i++) {
		if (check[i] > val) {
			idx = i;
			val = check[i];
			ok = true;
		}
		else if (check[i] == val) {
			ok = false;
		}
	}

	if (ok) {
		printf("%c\n", idx + 'A');
	}
	else {
		printf("?\n");
	}
	
	return 0;
}
