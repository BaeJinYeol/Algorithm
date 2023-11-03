#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int fibonacci[41][2];
	// fibonacci(0)의 값은 1, 0
	fibonacci[0][0] = 1;
	fibonacci[0][1] = 0;
	// fibonacci(1)의 값은 1, 1
	fibonacci[1][0] = 0;
	fibonacci[1][1] = 1;

	for (int i = 2; i <= 40; i++) {
		fibonacci[i][0] = fibonacci[i - 1][0] + fibonacci[i - 2][0];
		fibonacci[i][1] = fibonacci[i - 1][1] + fibonacci[i - 2][1];
	}

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		cout << fibonacci[n][0] << ' ' << fibonacci[n][1] << endl;
	}

	return 0;
}