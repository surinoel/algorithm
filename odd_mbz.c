#include <stdio.h>
#include <string.h>

int mat[5][5];

int main(int argc, char **argv)
{
    memset(mat, -1, sizeof(mat));
    int n = 1;
    int x = 1, y = 1;
    while(n <= 25) {
        if(--x == -1) x = 4;
        if(++y == 5) y = 0;
        
        if(mat[x][y] == -1) {
            mat[x][y] = n;
        }
        else {
            if(++x == 5) x = 0;
            if(--y == -1) y = 4;
            while(mat[x][y] != -1) {
                if(++x == 5) x = 0;
            }
            mat[x][y] = n;
        }
        n += 1;
    }

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
