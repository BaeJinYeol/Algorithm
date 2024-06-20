#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;	// n: 나무 갯수, m: 가져갈 나무 길이
	int h = 0;		// 절단기 길이

	cin >> n >> m;

	vector<int> namu(n);
	int max_hight = 0;

	for (int i = 0; i < n; i++) {
		cin >> namu[i];
		if (namu[i] > max_hight)
			max_hight = namu[i];
	}

	int left = 0, right = max_hight;

	while (left <= right) {
		int mid = (left + right) / 2;
		ll namu_s = 0;

		for (int i = 0; i < n; i++) {
			if (namu[i] > mid) {
				namu_s += namu[i] - mid;
			}
		}

		if (namu_s >= m) {
			h = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << h;

	return 0;
}