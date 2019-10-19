#include <iostream>

using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int arr[], int l, int r) {
	int pivot = arr[r];
	int i = l - 1;

	for (int j = l; j < r; j++) {
		if (pivot > arr[j]) {
			i++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return (i + 1);
}

void quicksort(int arr[], int l, int r) {
	if (l < r) {
		int p = partition(arr, l, r);

		quicksort(arr, l, p - 1);
		quicksort(arr, p + 1, r);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	quicksort(arr, 0, n - 1);
	cout << arr[n - 1] - arr[0] << '\n';
	delete[] arr;
	return 0;
}
