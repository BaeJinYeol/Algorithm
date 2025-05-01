#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> meeting(n);
	
	for (int i = 0; i < n; i++)
		cin >> meeting[i].first >> meeting[i].second;

	sort(meeting.begin(), meeting.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	});

	int count = 0;
	int end = 0;

	for (int i = 0; i < n; i++)
		if (meeting[i].first >= end) {
			end = meeting[i].second;
			count++;
		}

	cout << count << '\n';
	return 0;
}