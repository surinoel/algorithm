#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct tree {
	int p;
	int left, right;
	tree() : p(-1), left(-1), right(-1) {}
};

tree tr[10001];
int col = 1; 
int coldata[10001];
int dist[10001];
pair<int, int> level[10001];

void inorder(int idx) {
	if (idx == -1) {
		return;
	}
	
	inorder(tr[idx].left);
	coldata[idx] = col++;
	inorder(tr[idx].right);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p, l, r;
		cin >> p >> l >> r;
		tr[p].left = l, tr[p].right = r;
		tr[l].p = p, tr[r].p = p;
		level[i] = make_pair(0, 0);
 	}
	int root;
	for (int i = 1; i <= n; i++) {
		if (tr[i].p == -1) {
			root = i;
		}
	}

	inorder(root);
	queue<int> q;
	q.push(root);
	dist[root] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (tr[x].left != -1) {
			dist[tr[x].left] = dist[x] + 1;
			int height = dist[tr[x].left];
			if (level[height].first == 0 || level[height].first > coldata[tr[x].left]) {
				level[height].first = coldata[tr[x].left];
			}
			if (level[height].second == 0 || level[height].second < coldata[tr[x].left]) {
				level[height].second = coldata[tr[x].left];
			}
			q.push(tr[x].left);
		}
		if (tr[x].right != -1) {
			dist[tr[x].right] = dist[x] + 1;
			int height = dist[tr[x].right];
			if (level[height].first == 0 || level[height].first > coldata[tr[x].right]) {
				level[height].first = coldata[tr[x].right];
			}
			if (level[height].second == 0 || level[height].second < coldata[tr[x].right]) {
				level[height].second = coldata[tr[x].right];
			}
			q.push(tr[x].right);
		}
	}

	int ans = 1, height = 1;
	for (int i = 1; i <= n; i++) {
		if (level[i].first != 0 && level[i].second != 0) {
			if ((level[i].second - level[i].first + 1) > ans) {
				ans = level[i].second - level[i].first + 1;
				height = i;
			}
		}
	}
	cout << height << ' ' <<  ans << '\n';
	return 0;
}
