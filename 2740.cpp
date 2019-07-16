
#include <iostream>

using namespace std;

int a[100][100];
int b[100][100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	int u, v;
	cin >> u >> v;
	for (int i = 0; i < u; i++) {
		for (int j = 0; j < v; j++) {
			cin >> b[i][j];
		}
	}	 

	for (int i = 0; i < n; i++) {	
		for (int j = 0; j < v; j++) {	
			int sum = 0;
			for (int k = 0; k < u; k++) { 
				sum += a[i][k] * b[k][j];
			}
			cout << sum << ' ';
		}
		cout << '\n';
	}

	return 0;
}
