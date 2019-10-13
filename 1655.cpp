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

	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	int tc;
	cin >> tc;
	while (tc--) {
		int x; cin >> x;
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

		cout << max_heap.top() << '\n';
	}

	return 0;
}
