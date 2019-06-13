#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s1[64], s2[64];
char mat[64][64];

int main(void) {
	scanf("%s %s", s1, s2);

	int x, y;
	for (int i = 0; i < strlen(s1); i++) {
		for (int j = 0; j < strlen(s2); j++) {
			if (s1[i] == s2[j]) {
				x = j, y = i;
				goto end;
			}
		}
	}
	
end:
	for (int i = 0; i < strlen(s1); i++) {
		mat[x][i] = s1[i];
	}
	
	for (int j = 0; j < strlen(s2); j++) {
		mat[j][y] = s2[j];
	}
	
	for (int i = 0; i < strlen(s2); i++) {
		for (int j = 0; j < strlen(s1); j++) {
			if (mat[i][j] == 0) {
				printf(".");
			}
			else {
				printf("%c", mat[i][j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}
