#include <vector>
#include <iostream>

using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(vector<int>& arr, int l, int r) {
	int pivot = arr[r];
	int i = l - 1;

	for (int j = l; j <= r - 1; j++) {
		if (pivot > arr[j]) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[r]);
	return (i + 1);
}

void quicksort(vector<int>& arr, int l, int r) {
	if (l < r) {
		int p = partition(arr, l, r);

		quicksort(arr, l, p - 1);
		quicksort(arr, p + 1, r);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> a(4);
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}

	quicksort(a, 0, 3);
	cout << a[0] * a[2] << '\n';
	return 0;
}
