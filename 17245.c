#include <stdio.h>

#define max(n, m) n > m ? n : m

int d[10000001];

int main(void) {
	int n, max_height = 0;
	long long com_num = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int height;
			scanf("%d", &height);
			d[height] += 1;
			max_height = max(height, max_height);
			com_num += height;
		}
	}

	int ans;
	long long comp = com_num / 2;
	if (com_num % 2) {
		comp += 1;
	}
    if(max_height == 1) {
        ans = 1;
    }
    else {
        long long tmp = com_num;
	    for (int i = max_height; i > 0; i--) {
		    if (tmp < comp) {
		    	ans = i + 1;
		    	break;
		    }
		    else if (tmp == comp || i == 1) {
			    ans = i;
			    break;
		    }
		    tmp -= d[i];
		    d[i - 1] += d[i];
	    }
    }

	printf("%d\n", ans);
	return 0;
}
