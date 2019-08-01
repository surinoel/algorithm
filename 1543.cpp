#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m

vector<size_t> stidx;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	string a, b;
	getline(cin, a);
	getline(cin, b);

	int lenA = a.length();
	int lenB = b.length();

	for (int i = 0; i < lenA; i++) {
		if (!a.compare(i, lenB, b)) {
			stidx.push_back(i);
		}
	}

	int ans = 0;
	for (int i = 0; i < stidx.size(); i++) {
		size_t idx = stidx[i];
		int cnt = 0;
		while ((idx = a.find(b, idx)) != string::npos) {
			cnt += 1;
			idx += b.length();
		}

		ans = max(ans, cnt);
	}

	cout << ans << '\n';
	return 0;
}
