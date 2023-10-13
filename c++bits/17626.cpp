#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> DP(50001, 0);
	DP[1] = 1;
	for (int i = 2; i <= n; i++) {
		int minN = INT_MAX;
		for (int j = 1; j * j <= i; j++) {
			int temp = i - j * j;
			minN = min(minN, DP[temp]);
		}
		DP[i] = minN + 1;
	}
	cout << DP[n] << '\n';
	return 0;
}