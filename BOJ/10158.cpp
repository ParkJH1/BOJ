#include <iostream>
using namespace std;
int main()
{
	int w, h;
	int p, q;
	int t;
	cin >> w >> h;
	cin >> p >> q;
	cin >> t;
	int x = p + t % (2 * w);
	int y = q + t % (2 * h);
	if (x >= 2 * w) x = x - 2 * w;
	else if (x > w) x = 2 * w - x;
	if (y >= 2 * h) y = y - 2 * h;
	else if (y > h) y = 2 * h - y;
	cout << x << " " << y;
	return 0;
}