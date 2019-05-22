#include <iostream>

using namespace std;

int d[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int s, e;
	cin >> s >> e;
	int idx = 1;
	long long sum = 0;
	for(int i=1; i<=1000; i++) {
		for(int j=1; j<=i; j++) {
			if(idx >= s && idx <= e) {
				sum += i;
			}
			idx++;
		}
	}
	
	cout << sum <<'\n';
	return 0;
}
