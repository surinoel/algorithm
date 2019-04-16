#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int x;
	cin >> x;
	vector<bool> check(x+1, true);
	vector<int> prime;
	check[1] = false;
	for (int i = 2; i * i <= x; i++) {
		if (!check[i]) continue;
		for (int j = i + i; j <= x; j += i) {
			check[j] = false;
		}
	}
	
	for (int i = 2; i <= x; i++) {
		if(check[i]) prime.push_back(i);
	}
	
	int cnt = 0;
	int left, right;
	left = right = 0;
	
	if (!prime.empty()) {
		int sum = prime[left];
		while (left <= right && prime[right] <= x) {
			if (sum < x) {
				if (++right != prime.size()) {
					sum += prime[right];
				}
				else {
					break;
				}
			}
			else if (sum == x) {
				cnt++;
				if (++right != prime.size()) {
					sum += prime[right];
				}
				else {
					break;
				}
			}
			else {
				sum -= prime[left++];
			}
		}
	}
	
	cout << cnt << '\n';
	return 0;
}
