#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct POS {
	int x, y, z;
	int day;
};

int main()
{
	int m, n, h;
	cin >> m >> n >> h;
	vector<vector<vector<int>>> box(h, vector<vector<int>>(n, vector<int>(m)));
	int tomato = 0, blank = 0;
	queue<POS> q;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					tomato += 1;
					POS p;
					p.z = i;
					p.y = j;
					p.x = k;
					p.day = 0;
					q.push(p);
				}
				else if (box[i][j][k] == -1) blank += 1;
			}
		}
	}

	int dz[] = { -1,1,0,0,0,0 };
	int dy[] = { 0,0,1,-1,0,0 };
	int dx[] = { 0,0,0,0,1,-1 };

	int answer = 0;

	while (!q.empty()) {
		POS now = q.front();
		q.pop();
		answer = now.day;
		for (int i = 0; i < 6; i++) {
			POS next;
			next.z = now.z + dz[i];
			next.y = now.y + dy[i];
			next.x = now.x + dx[i];
			next.day = now.day + 1;
			if (next.z >= 0 && next.z < h  && next.y >= 0 && next.y < n && next.x >= 0 && next.x < m) {
				if (box[next.z][next.y][next.x] == 0) {
					box[next.z][next.y][next.x] = 1;
					tomato += 1;
					q.push(next);
				}
			}
		}
	}

	if (tomato + blank == n * m*h) cout << answer;
	else cout << -1;

	return 0;
}