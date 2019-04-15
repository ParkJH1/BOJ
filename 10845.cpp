#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	queue<int> q;
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd[0] == 'p') {// push,pop
			if (cmd[1] == 'u') {//push
				int x;
				cin >> x;
				q.push(x);
			}
			else if (cmd[1] == 'o') {//pop
				if (q.empty()) cout << "-1\n";
				else {
					cout << q.front() << "\n";
					q.pop();
				}
			}
		}
		else if (cmd[0] == 's') {// size
			cout << q.size() << "\n";
		}
		else if (cmd[0] == 'e') {// empty
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (cmd[0] == 'f') {// front
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << "\n";
			}
		}
		else if (cmd[0] == 'b') {// back
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.back() << "\n";
			}
		}
	}

	return 0;
}