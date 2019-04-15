#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> card;
	for (int i = 1; i <= 20; i++) card.push_back(i);
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		reverse(card.begin() + a - 1, card.begin() + b);
		/*for (int j = 0; j < (b - a + 1) / 2; j++) {
			int tmp = card[a + j];
			card[a + j] = card[b - j];
			card[b - j] = tmp;
		}*/
	}
	for (int c : card) cout << c << " ";
	return 0;
}