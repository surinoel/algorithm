#include <queue>
#include <vector>
#include <string>
#include <cstring> 
#include <algorithm>
#include <functional>

using namespace std;

vector<int> mat[20001];
int dist[20001];

int solution(int n, vector<vector<int>> edge) {
	int ans = 1;
	for (int i = 0; i < edge.size(); i++) {
		int ndx = edge[i][0];
		int ndy = edge[i][1];
		mat[ndx].push_back(ndy);
		mat[ndy].push_back(ndx);
	}
    
  memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(1);
	dist[1] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		for (int k = 0; k < mat[x].size(); k++) {
			int node = mat[x][k];
			if (dist[node] == -1) {
				dist[node] = dist[x] + 1;
				q.push(node);
			}
		}
	}

	sort(dist + 1, dist + 1 + n, greater<int>());
	int val = dist[1];
	for (int i = 2; i <= n; i++) {
		if (val != dist[i]) {
			break;
		}
		ans += 1;
	}
	return ans;
}
