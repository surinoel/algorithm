#include <queue>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		priority_queue<int> max_heap;
		priority_queue<int, vector<int>, greater<int>> min_heap;

		int n;
		cin >> n;
		vector<int> ans;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			
			if (max_heap.size() == min_heap.size()) {
				max_heap.push(x);
			}
			else {
				min_heap.push(x);
			}

			if (!max_heap.empty() && !min_heap.empty()
				&& max_heap.top() > min_heap.top()) {
				int a = max_heap.top();
				int b = min_heap.top();

				swap(&a, &b);

				max_heap.pop();
				min_heap.pop();

				max_heap.push(a);
				min_heap.push(b);
			}

			if (i % 2) {
				ans.push_back(max_heap.top());
			}
		}

		cout << ans.size() << '\n';
		for (int i = 1; i <= ans.size(); i++) {
			cout << ans[i - 1] << ' ';
			if (i % 10 == 0) cout << '\n';
		}
		cout << '\n';
	}

	return 0;
}
