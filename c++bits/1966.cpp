#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test, n, m, impt;
	cin >> test;
	
	for (int i = 0; i < test; i++) {
		cin >> n >> m;
		int docu, count = 0;
		queue<pair<int, int>> que;
		priority_queue<int> pque;
		
		for (int j = 0; j < n; j++) {
			cin >> impt;
			que.push({ j, impt });
			pque.push(impt);
		}
		while (!que.empty()) {
			int idx = que.front().first;
			int value = que.front().second;
			que.pop();
			if (pque.top() == value) {
				pque.pop();
				count++;
				if (idx == m) {
					cout << count << '\n';
					break;
				}
			}
			else que.push({ idx, value });
		}
	}

	return 0;
}