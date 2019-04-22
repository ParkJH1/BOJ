#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int t = 60 * a + b + c;
	t %= 1440;
	cout << t / 60 << " " << t % 60;
	return 0;
}