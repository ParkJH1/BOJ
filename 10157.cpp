#include <iostream>
using namespace std;
int main()
{
	int c, r, k;
	cin >> c >> r;
	cin >> k;
	if (c*r < k) cout << "0";
	else {
		int x = 1, y = 0;
		int dx = 1, dy = 1;
		c -= 1;
		while (true) {
			for (int i = 0; i < r; i++) {
				y += dy;
				k -= 1;
				if (k == 0) break;
			}
			if (k == 0) break;
			r -= 1;
			dy *= -1;
			for (int i = 0; i < c; i++) {
				x += dx;
				k -= 1;
				if (k == 0) break;
			}
			if (k == 0) break;
			c -= 1;
			dx *= -1;
		}
		cout << x << " " << y;
	}
	return 0;
}