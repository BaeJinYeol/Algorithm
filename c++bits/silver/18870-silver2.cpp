///	
///	좌표 압축
/// 정렬, 값 압축
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<ll> points(n);
	vector<ll> sort_points(n);
	map<int, int> compression;
	for (int i = 0; i < n; i++) {
		cin >> points[i];
		sort_points[i] = points[i];
	}
	// 중복 제거 및 정렬
	sort(sort_points.begin(), sort_points.end());
	sort_points.erase(unique(sort_points.begin(), sort_points.end()), sort_points.end());

	// 좌표 압축
	for (int i = 0; i < sort_points.size(); i++)
		compression[sort_points[i]] = i;

	// 출력
	for (int i = 0; i < n; i++)
		cout << compression[points[i]] << " ";

	return 0;
}