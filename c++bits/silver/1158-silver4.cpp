///	
///	요세푸스 문제
/// 자료구조, 큐
/// 

#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		q.push(i);

	cout << '<';
	while (q.size() != 1) {
		for (int i = 1; i < k; i++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << '>';

	return 0;
}