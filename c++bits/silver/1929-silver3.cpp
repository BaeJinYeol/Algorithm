#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;

    vector<int> isPrime(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        isPrime[i] = i;
    }

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i] == 0) continue;
        for (int j = i * i; j <= n; j += i) {
            if (isPrime[j] == 0)  continue;
            else isPrime[j] = 0;
        }
    }

	for (int i = m; i <= n; i++)
		if (isPrime[i] != 0) cout << isPrime[i] << '\n';

	return 0;
}