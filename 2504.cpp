#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>	// 스택 헤더파일 추가
#include <string>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string str;
	cin >> str;

	stack<char> st1;
	bool check = true;
	for (char ch : str) {
		if (ch == '(' || ch == '[') st1.push(ch);
		else if (ch == ')') {
			if (!st1.empty() && st1.top() == '(') {
				st1.pop();
			}
			else check = false;
		}
		else if (ch == ']') {
			if (!st1.empty() && st1.top() == '[') {
				st1.pop();
			}
			else check = false;
		}
	}

	// 올바르지않을때
	if (!st1.empty() || !check) {
		cout << "0";
		return 0;
	}

	// '(' : -1, '[' : -2
	stack<int> st2;
	for (char ch : str) {
		if (ch == '(') st2.push(-1);
		else if (ch == '[') st2.push(-2);
		else if (ch == ')') {
			int sum = 0;
			while (st2.top() != -1) {
				sum += st2.top();
				st2.pop();
			}
			st2.pop();
			if (sum == 0) st2.push(2);
			else st2.push(sum * 2);
		}
		else if (ch == ']') {
			int sum = 0;
			while (st2.top() != -2) {
				sum += st2.top();
				st2.pop();
			}
			st2.pop();
			if (sum == 0) st2.push(3);
			else st2.push(sum * 3);
		}
	}
	int answer = 0;
	while (!st2.empty()) {
		answer += st2.top();
		st2.pop();
	}
	cout << answer;

	return 0;
}

