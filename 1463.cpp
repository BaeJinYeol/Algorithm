#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> memo(n+1, 0);

	memo[1] = 0;
	memo[2] = 1;
	memo[3] = 1;

	for (int i = 4; i <= n; i++) {
		memo[i] = memo[i - 1] + 1;
		if (i % 3 == 0) memo[i] = min(memo[i / 3] + 1, memo[i]);
		if (i % 2 == 0) memo[i] = min(memo[i / 2] + 1, memo[i]);
	}

	cout << memo[n] << endl;

	return 0;
}