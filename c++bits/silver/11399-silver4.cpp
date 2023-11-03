#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareTime(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> plist;

	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		plist.push_back(make_pair(p, i));
	}

	sort(plist.begin(), plist.end(), compareTime);

	int sum = 0, result = 0;
	for (const pair<int, int>& i : plist) {
		sum += i.first;
		result += sum;
	}

	cout << result << '\n';

	return 0;
}