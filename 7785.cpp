#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;

	set<string> company;
	while (n--) {
		string name, lg;
		cin >> name >> lg;
		if (lg[0] == 'e') {	//enter
			company.insert(name);	// O(logn)
		}
		else {	//leave	// O(logn)
			company.erase(name);
		}
	}
	for(auto it=company.rbegin(); it!=company.rend(); it++)
		cout << *it << "\n";

	return 0;
}