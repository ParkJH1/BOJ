#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n, l, m;
	cin >> n >> l >> m;
	vector<pair<int, int>> fish(m);
	vector<int> y, x;
	for (int i = 0; i < m; i++) {
		cin >> fish[i].first >> fish[i].second;
		y.push_back(fish[i].first);
		x.push_back(fish[i].second);
	}
	sort(y.begin(), y.end());
	sort(x.begin(), x.end());
	auto yend = unique(y.begin(), y.end());
	auto xend = unique(x.begin(), x.end());
	vector<vector<int>> sea(yend - y.begin(), vector<int>(xend - x.begin()));
	for (int i = 0; i < m; i++) {
		int yidx, xidx;
		for (auto it = y.begin(); it != yend; it++) {
			if (*it == fish[i].first) {
				yidx = it - y.begin();
				break;
			}
		}
		for (auto it = x.begin(); it != xend; it++) {
			if (*it == fish[i].second) {
				xidx = it - x.begin();
				break;
			}
		}
		sea[yidx][xidx] = 1;
	}

	for (int i = 0; i < sea.size(); i++) {
		for (int j = 0; j < sea[i].size(); j++) {
			if (i > 0) sea[i][j] += sea[i - 1][j];
			if (j > 0) sea[i][j] += sea[i][j - 1];
			if (i > 0 && j > 0) sea[i][j] -= sea[i - 1][j - 1];
		}
	}

	int answer = 0;
	l /= 2;

	for (auto it1 = y.begin(); it1 != yend; it1++) {
		for (auto it2 = x.begin(); it2 != xend; it2++) {
			int sy = *it1;
			int sx = *it2;
			for (int i = 1; i < l; i++) {
				int ey = sy + i;
				int ex = sx + l - i;

				int syidx = it1 - y.begin();
				int sxidx = it2 - x.begin();
				int eyidx = upper_bound(y.begin(), yend, ey) - y.begin() - 1;
				int exidx = upper_bound(x.begin(), xend, ex) - x.begin() - 1;
				
				int nowanswer = sea[eyidx][exidx];
				if (syidx > 0) nowanswer -= sea[syidx - 1][sxidx];
				if (sxidx > 0) nowanswer -= sea[syidx][sxidx - 1];
				if (syidx > 0 && sxidx > 0) nowanswer += sea[syidx - 1][sxidx - 1];

				if (nowanswer == 5) {
					nowanswer = nowanswer;
				}
				answer = max(answer, nowanswer);
			}
		}
	}

	cout << answer;

	return 0;
}