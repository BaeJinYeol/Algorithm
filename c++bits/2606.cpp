#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> net) {
	queue<int> q;
	// 1번 노드부터 bfs탐색 실행
	int start = 1;
	q.push(start);
	int size = net.size();
	vector<bool> visit(size, false);
	visit[start] = true;
	int count = 0;

	while (!q.empty()) {
		// 큐에 값이 있을경우 계속 반복 실행
		// 큐에 값이 있다. => 아직 방문하지 않은 노드가 존재 한다.
		int x = q.front();
		q.pop();
		
		for (int i = 0; i < net[x].size(); i++) {
			int y = net[x][i];
			if (!visit[y]) {
				// 방문하지 않았다면..
				q.push(y);
				visit[y] = true;
				count++;
			}
		}
	}
	cout << count << endl;
}

int main() {
	int com_num, connected_num;
	cin >> com_num >> connected_num;
	
	vector<vector<int>> net(com_num + 1);
	for (int i = 0; i < connected_num; i++) {
		int a, b;
		cin >> a >> b;
		net[a].push_back(b);
		net[b].push_back(a);
	}

	BFS(net);
	
	return 0;
}