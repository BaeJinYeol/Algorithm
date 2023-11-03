#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, x;
	// 최소힙 priority_queue<int>는 최대힙
	priority_queue<int, vector<int>, greater<int>> minHeap;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x > 0) {
			minHeap.push(x);
		}
		else {
			if (minHeap.empty()) cout << 0 << '\n';
			else {
				cout << minHeap.top() << '\n';
				minHeap.pop();
			}
		}
	}

	return 0;
}