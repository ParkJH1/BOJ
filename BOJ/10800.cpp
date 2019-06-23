#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	// (크기, 원본인덱스)
	vector<pair<int, int>> ball(n);
	// 색별로 나눈 데이터
	vector<vector<pair<int, int>>> colorball(n);
	vector<int> answer(n);

	for (int i = 0; i < n; i++) {
		int color, size;
		cin >> color >> size;
		ball[i] = { size,i };
		colorball[color - 1].push_back({ size,i });
	}

	sort(ball.begin(), ball.end());
	for (int i = 0; i < n; i++)
		sort(colorball[i].begin(), colorball[i].end());

	int sum = 0, tmp = 0;
	for (int i = 1; i < n; i++) {
		if (ball[i].first == ball[i - 1].first) {
			tmp += ball[i - 1].first;
			answer[ball[i].second] += sum;
		}
		else {
			sum += ball[i - 1].first + tmp;
			tmp = 0;
			answer[ball[i].second] += sum;
		}
	}

	for (int i = 0; i < n; i++) {
		sum = 0, tmp = 0;
		for (int j = 1; j < colorball[i].size(); j++) {
			if (colorball[i][j].first == colorball[i][j - 1].first) {
				tmp += colorball[i][j - 1].first;
				answer[colorball[i][j].second] -= sum;
			}
			else {
				sum += colorball[i][j - 1].first + tmp;
				tmp = 0;
				answer[colorball[i][j].second] -= sum;
			}
		}
	}

	for (int ans : answer) cout << ans << "\n";

	return 0;
}