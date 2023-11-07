///	
///	숨바꼭질
/// 그래프, 너비 우선 탐색
/// 

#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];

void BFS(int n, int k) {
	queue<pair<int, int>> q;	// 큐에 (위치, 시간)을 저장
	q.push({n, 0});

	while (!q.empty()) {
		int cur_pos = q.front().first;
		int cur_time = q.front().second;
		q.pop();

		if (cur_pos == k) {
			cout << cur_time << endl;
			break;
		}

		if (cur_pos - 1 >= 0 && !visited[cur_pos - 1]) {
			q.push({ cur_pos - 1, cur_time + 1 });
			visited[cur_pos - 1] = true;
		}
		if (cur_pos + 1 <= 100000 && !visited[cur_pos + 1]) {
			q.push({ cur_pos + 1, cur_time + 1 });
			visited[cur_pos + 1] = true;
		}
		if (cur_pos * 2 <= 100000 && !visited[cur_pos * 2]) {
			q.push({ cur_pos * 2, cur_time + 1 });
			visited[cur_pos * 2] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	visited[n] = true;

	BFS(n, k);

	return 0;
}