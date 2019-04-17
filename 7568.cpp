#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> person(n);
	for (int i = 0; i < n; i++) {
		cin >> person[i].first >> person[i].second;
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (person[i].first < person[j].first && person[i].second < person[j].second)
				cnt += 1;
		}
		cout << cnt + 1 << " ";
	}
	return 0;
}