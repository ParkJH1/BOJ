#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	set<string> listen;
	set<string> answer;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		listen.insert(name);
	}

	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		auto ret = listen.find(name);
		if (ret != listen.end()) answer.insert(name);
	}

	cout << answer.size() << "\n";
	//for (auto it = answer.begin(); it != answer.end(); it++) {
	//	cout << *it << "\n";
	//}
	for (string s : answer) {
		cout << s << "\n";
	}

	return 0;
}