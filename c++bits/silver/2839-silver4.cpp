#include <iostream>
using namespace std;

int sugar() 
{
	int N, count5 = 0, count3 = 0;
	cin >> N;

	if (N >= 5) {
		count5 += N / 5;
		N = (N % 5);
	}
	if (N >= 3) {
		count3 += N / 3;
		N = (N % 3);
	}
	if (N == 0)
		return count5 + count3;

	while (count5 > 0) {
		count5--;
		N += 5;

		count3 += N / 3;
		N = (N % 3);

		if (N == 0)
			return count5 + count3;
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << sugar() << '\n';

	return 0;
}