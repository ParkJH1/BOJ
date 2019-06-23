#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		queue<pair<int, int>> q;
		vector<int> p;
		cin >> n >> m;
		vector<int> order(n);
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			p.push_back(tmp);
			q.push({ tmp,i });
		}
		sort(p.rbegin(), p.rend());
		for (int i = 0; i < p.size(); i++) {
			int nowp = p[i];
			while (true) {
				if (q.front().first == nowp) {
					order[q.front().second] = i + 1;
					q.pop();
					break;
				}
				else {
					q.push(q.front());
					q.pop();
				}
			}
		}
		cout << order[m] << "\n";
	}
	return 0;
}