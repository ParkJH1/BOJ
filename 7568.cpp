#include <iostream>
#include <vector>
using namespace std;

bool operator<(pair<int, int> &p1, pair<int, int> &p2) {
	return p1.first < p2.first && p1.second < p2.second;
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> person(n);
	for (int i = 0; i < n; i++) cin >> person[i].first >> person[i].second;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (person[i] < person[j]) cnt += 1;
		}
		cout << cnt << " ";
	}
}