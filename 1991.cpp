#include <iostream>

using namespace std;

struct tree {
	int left, right;
	tree() : left(-1), right(-1) {}
};

tree tr[26];

void preorder(int t) {
	if (t == -1) {
		return;
	}
	cout << (char)(t + 'A');
	preorder(tr[t].left);
	preorder(tr[t].right);
}

void inorder(int t) {
	if (t == -1) {
		return;
	}
	inorder(tr[t].left);
	cout << (char)(t + 'A');
	inorder(tr[t].right);
}

void postorder(int t) {
	if (t == -1) {
		return;
	}
	postorder(tr[t].left);
	postorder(tr[t].right);
	cout << (char)(t + 'A');
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char x, y, z;
		cin >> x >> y >> z;
		if (y == '.') tr[x - 'A'].left = -1;
		else tr[x - 'A'].left = y - 'A';
		
		if (z == '.') tr[x - 'A'].right = -1;
		else tr[x - 'A'].right = z - 'A';
	}

	preorder(0); cout << '\n';
	inorder(0); cout << '\n';
	postorder(0); cout << '\n';

	return 0;
}
