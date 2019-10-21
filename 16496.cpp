#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];

bool cmp(const int &u, const int &v) {
	string a = to_string(u) + to_string(v);
	string b = to_string(v) + to_string(u);

	return a > b;
}
 
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, cmp);
	string ans = "";
	for (int i = 0; i < n; i++) {
		ans += to_string(arr[i]);
	}
	if (ans.length() > 1 && ans[0] == '0') {
		ans = "0";
	}
	cout << ans << '\n';
	return 0;
}
