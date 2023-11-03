#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparePoint(const pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;

	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, i;
	cin >> N;

	vector<pair<int, int>> points(N);

	for (i = 0; i < N; i++)
		cin >> points[i].first >> points[i].second;

	sort(points.begin(), points.end(), comparePoint);

	for (pair<int, int> point : points)
		cout << point.first << " " << point.second << '\n';

	return 0;
}