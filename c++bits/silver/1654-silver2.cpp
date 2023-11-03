#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k, n;
	cin >> k >> n;

	vector<ll> lan;
	
	for (int i = 0; i < k; i++) {
		ll tmp;
		cin >> tmp;
		lan.push_back(tmp);
	}

	sort(lan.begin(), lan.end());

	ll left = 1; // 최소
	ll right = lan.back(); // 최대

	while (left <= right) {
		ll mid = (left + right) / 2; // 중간 길이
		int count = 0;
		
		for (int i = 0; i < k; i++)
			count += lan[i] / mid;

		if (count >= n) left = mid + 1;
		else right = mid - 1;
	}

	cout << right << '\n';

	return 0;
}