#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/*
	Á¡È­½Ä
	DP[N] = (DP[N-2] + STAIR[N]) or (DP[N-3] + STAIR[N-1] + STAIR[N])
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> stair(n + 1, 0);
	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> stair[i];
	}

	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
	int step = 0;

	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}

	cout << dp[n] << endl;

	return 0;
}