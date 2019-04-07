#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	cout << "<";
	while (q.size() > 1) {
		for (int i = 0; i < k - 1; i++) {
			int x = q.front();
			q.pop();
			q.push(x);
		}

		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">\n";
	return 0;
}