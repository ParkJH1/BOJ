#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int answer = 10;
	for (int i = 1; i < s.length(); i++) {
		if (s[i - 1] == s[i]) answer += 5;
		else answer += 10;
	}
	cout << answer;
	return 0;
}