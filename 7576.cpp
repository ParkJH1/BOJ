#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> box(m, vector<int>(n));
	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) q.push({ i,j });
		}
	}
	while (!q.empty()) {
		auto pos = q.front();
		q.pop();
	}

	return 0;
}