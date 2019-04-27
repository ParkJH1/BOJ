#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	vector<int> v(n);
	vector<int> cnt(d + 1);
	for (int i = 0; i < n; i++) cin >> v[i];
	int s = 0, e = k - 1;
	int answer = 0, nowanswer = 0;
	for (int i = s; i <= e; i++) {
		if (cnt[v[i]] == 0) nowanswer += 1;
		cnt[v[i]] += 1;
	}
	answer = max(answer, nowanswer + ((cnt[c] == 0) ? 1 : 0));
	while (s < n) {
		cnt[v[s]] -= 1;
		if (cnt[v[s]] == 0) nowanswer -= 1;
		s += 1;
		e = (e + 1) % n;
		if (cnt[v[e]] == 0) nowanswer += 1;
		cnt[v[e]] += 1;
		answer = max(answer, nowanswer + ((cnt[c] == 0) ? 1 : 0));
	}
	cout << answer;
	return 0;
}