#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>

#define MOD 20150523

using namespace std;
using pii = pair<int, int>;
using ll = long long;

vector<vector<int>> dp1;
vector<int> dp2, dp3;

int get1(int n, int p)
{
	int& ret = dp1[n][p];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 10; i++) {
		if (i == 3 || i == 6 || i == 9) continue;
		ret = (ret + get1(n - 1, (p - i + 30) % 3)) % MOD;
	}
	return ret;
}

int get2(int n)
{
	int& ret = dp2[n];
	if (ret != -1) return ret;
	ret = (get2(n - 1) * 10) % MOD;
	return ret;
}

int get3(int n)
{
	int& ret = dp3[n];
	if (ret != -1) return ret;
	ret = (get3(n - 1) * 7) % MOD;
	return ret;
}

int getAnswer2(string num)
{
	int ret = 0;
	int nn = atoi(num.c_str());
	for (int i = 0; i <= nn; i++) {
		bool check = false;
		int tmp = i;
		while (tmp != 0) {
			if (tmp % 10 == 3 || tmp % 10 == 6 || tmp % 10 == 9) check = true;
			tmp /= 10;
		}
		if (i % 3 == 0) check = true;
		if (check) ret += 1;
	}
	return ret;
}

int getAnswer(string num)
{
	int ret = 0;

	int sum = 0;
	bool check = false;
	for (int i = 0; i < num.length(); i++) {
		int now = num[i] - '0';
		int nowlen = num.length() - 1 - i;
		for (int j = 0; j < now; j++) {
			int nowsum = (sum + j) % 3;
			if (nowlen > 0) {
				ret = (ret + get2(nowlen)) % MOD;
				if (!check && j != 3 && j != 6 && j != 9) {
					ret = (ret - get3(nowlen) + MOD) % MOD;
					ret = (ret + get1(nowlen, (3 - nowsum) % 3)) % MOD;
				}
			}
			else if (check || j == 3 || j == 6 || j == 9 || nowsum % 3 == 0) ret = (ret + 1) % MOD;
		}
		sum = (sum + now) % 3;
		if (now == 3 || now == 6 || now == 9) check = true;
	}
	if (check || sum == 0) ret = (ret + 1) % MOD;
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	cin >> a >> b;

	dp1.resize(b.length(), vector<int>(3, -1));
	dp2.resize(b.length(), -1);
	dp3.resize(b.length(), -1);

	dp1[0][0] = 1;
	dp1[0][1] = 0;
	dp1[0][2] = 0;
	dp2[0] = 1;
	dp3[0] = 1;

	int answer = (getAnswer(b) - getAnswer(a) + MOD) % MOD;;
	bool check = false;
	int sum = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '3' || a[i] == '6' || a[i] == '9') check = true;
		sum += a[i] - '0';
	}
	if (sum % 3 == 0) check = true;
	if (check) answer = (answer + 1) % MOD;
	cout << answer;

	return 0;
}
