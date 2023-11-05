///	
///	��ǥ ����
/// ����, �� ����
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
	// �ߺ� ���� �� ����
	sort(sort_points.begin(), sort_points.end());
	sort_points.erase(unique(sort_points.begin(), sort_points.end()), sort_points.end());

	// ��ǥ ����
	for (int i = 0; i < sort_points.size(); i++)
		compression[sort_points[i]] = i;

	// ���
	for (int i = 0; i < n; i++)
		cout << compression[points[i]] << " ";

	return 0;
}