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
	//sort(y.begin(), y.end());
	//sort(x.begin(), x.end());
	auto yend = unique(y.begin(), y.end());
	auto xend = unique(x.begin(), x.end());
	sort(y.begin(), yend);
	sort(x.begin(), xend);

	//0 1 2 3 4 5 6 7 8 9
	//4 4 4 4 4 4 4 5 3  
	//b                 e
	//4 5 3 4 4 4 4 4 4
	//b     e

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

	// 누적합 구성
	for (int i = 0; i < sea.size(); i++) {
		for (int j = 0; j < sea[i].size(); j++) {
			//sea[i][j] = sea[i][j] + sea[i - 1][j] + sea[i][j - 1] - sea[i - 1][j - 1];
			if (i > 0) sea[i][j] += sea[i - 1][j];
			if (j > 0) sea[i][j] += sea[i][j - 1];
			if (i > 0 && j > 0) sea[i][j] -= sea[i - 1][j - 1];
		}
	}

	/*
	2a + 2b = l
	a + b = l/2
	a = 1 ~ (l/2 - 1)
	b = l - a
	*/
	int answer = 0;
	l /= 2;
	for (auto ity = y.begin(); ity != yend; ity++) {
		for (auto itx = x.begin(); itx != xend; itx++) {
			for (int a = 1; a < l; a++) {
				int b = l - a;
				// 고기 수를 구하고 최댓값 구하기
				int ey = *ity + a;
				int ex = *itx + b;
				int syidx = ity - y.begin(), sxidx = itx - x.begin();
				int eyidx = yend - y.begin() - 1, exidx = xend - x.begin() - 1;
				for (auto it = y.begin(); it != yend; it++) {
					if (*it > ey) {
						eyidx = it - y.begin() - 1;
						break;
					}
				}
				for (auto it = x.begin(); it != xend; it++) {
					if (*it > ex) {
						exidx = it - x.begin() - 1;
						break;
					}
				}
				
				int nowanswer = sea[eyidx][exidx];
				if (syidx > 0) nowanswer -= sea[syidx - 1][exidx];
				if (sxidx > 0) nowanswer -= sea[eyidx][sxidx - 1];
				if (sxidx > 0 && syidx > 0) nowanswer += sea[syidx - 1][sxidx - 1];

				answer = max(answer, nowanswer);
			}
		}
	}
	cout << answer;

	return 0;
}