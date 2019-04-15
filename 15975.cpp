#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string str;
	cin >> str;
	stack<int> st;
	// '(' : -1
	int answer = 0;
	for (char ch : str) {
		if (ch == '(') st.push(-1);
		else {
			int lazer = 0;
			while (!st.empty()) {
				int top = st.top();
				st.pop();
				if (top == -1) break;
				lazer += top;
			}
			if (lazer == 0) st.push(1);
			else {
				answer += lazer + 1;
				st.push(lazer);
			}
		}
	}
	cout << answer;
	return 0;
}