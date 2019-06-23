#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	stack<int> st;
	vector<char> answer;
	int apos = 0;
	for (int i = 1; i <= n; i++) {
		st.push(i);
		answer.push_back('+');
		while(!st.empty()){
			if (st.top() == a[apos]) {
				st.pop();
				answer.push_back('-');
				apos += 1;
			}
			else break;
		}
	}
	if (st.empty()) {	// 스택수열이 완성됬을 때
		for (char ch : answer) cout << ch << "\n";
	}
	else {	// 불가능한 경우
		cout << "NO";
	}

	return 0;
}
