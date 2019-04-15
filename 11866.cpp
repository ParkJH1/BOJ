#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	queue<int> q;
	vector<int> answer;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) q.push(i);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m - 1; j++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		answer.push_back(q.front());
		q.pop();
	}
	cout << "<" << answer[0];
	for (int i = 1; i < answer.size(); i++) cout << ", " << answer[i];
	cout << ">";
	return 0;
}