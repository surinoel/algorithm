#include <cmath>
#include <string>
#include <iostream>

using namespace std;

void hanoi(int n, int start, int mid, int end) {
	if (n == 0) {
		return;
	}
	
	hanoi(n - 1, start, end, mid);
	cout << start << ' ' << end << '\n';
	hanoi(n - 1, mid, start, end);
}

string bigsum(string s1, string s2) {
	int carry = 0;
	string ans = "";
	for (int i = s1.size() - 1; i >= 0; i--) {
		int sum = s1[i] - '0' + s2[i] - '0' + carry;
		carry = sum / 10;
		string tmp = to_string(sum % 10);
		ans = tmp + ans;
	}
	if (carry) {
		ans = '1' + ans;
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	if (n <= 20) {
		cout << (int)pow(2, n) - 1 << '\n';
		hanoi(n, 1, 2, 3);
	}
	else {
		string tmp = "2";
		for (int i = 0; i < n - 1; i++) {
			string ans = bigsum(tmp, tmp);
			tmp = ans;
		}
		tmp[tmp.size() - 1] -= 1;
		cout << tmp << '\n';
	}

	return 0;
}
