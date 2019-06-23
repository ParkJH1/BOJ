#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int n;
	map<string, int> lib;
	int maxcnt = 1;
	cin >> n;
	while (n--) {
		string title;
		cin >> title;
		auto ret = lib.insert({ title,1 });
		if (!ret.second) {	// 이미 도서관이 이 책이 있음
			(*ret.first).second += 1;
			//ret.first->second += 1;
			if (maxcnt < (*ret.first).second)
				maxcnt = (*ret.first).second;
		}
	}
	for (auto book : lib) {
		if (book.second == maxcnt) {
			cout << book.first;
			break;
		}
	}
	return 0;
}