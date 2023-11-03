#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

// cout.tie(NULL)을 추가하고, endl 대신 '\n'을 사용하니 성공
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	ll temp, sum = 0;
	cin >> n >> m;
	vector<ll> num(100001);
	num[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		num[i] = num[i - 1] + temp;
	}

	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << int(num[j] - num[i - 1]) << '\n';
	}

	return 0;
}