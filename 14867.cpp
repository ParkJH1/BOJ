#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	queue<pair<pair<int, int>, int>> q;
	set<pair<int, int>> check;
	q.push({ {0,0},0 });
	check.insert({ 0,0 });

	while (!q.empty()) {
		auto qf = q.front();
		auto now = qf.first;
		q.pop();

		if (now.first == c && now.second == d) {
			cout << qf.second;
			return 0;
		}
		
		pair<int, int> next;
		// Fill a
		next.first = a;
		next.second = now.second;
		//auto ret = check.insert(next);
		//if(ret.second) q.push({ next,qf.second + 1 });
		if (check.insert(next).second) q.push({ next,qf.second + 1 });

		// Fill b
		next.first = now.first;
		next.second = b;
		if (check.insert(next).second) q.push({ next,qf.second + 1 });

		// Empty a
		next.first = 0;
		next.second = now.second;
		if (check.insert(next).second) q.push({ next,qf.second + 1 });

		// Empty b
		next.first = now.first;
		next.second = 0;
		if (check.insert(next).second) q.push({ next,qf.second + 1 });

		// M(x,y)
		if (now.second + now.first > b) {
			next.first = now.first - (b - now.second);
			next.second = b;
		}
		else {
			next.first = 0;
			next.second = now.second + now.first;
		}
		if (check.insert(next).second) q.push({ next,qf.second + 1 });

		// M(y,x)
		if (now.first + now.second > a) {
			next.first = a;
			next.second = now.second - (a - now.first);
		}
		else {
			next.first = now.first + now.second;
			next.second = 0;
		}
		if (check.insert(next).second) q.push({ next,qf.second + 1 });
	}

	cout << -1;

	return 0;
}
