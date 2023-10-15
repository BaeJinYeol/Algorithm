#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[1001];
vector<int> graph[10001];

void BFS(int start) {
	queue<int> q;
	q.push(start);			// 첫 노드를 queue에 삽입
	visited[start] = true;	// 첫 노드를 방문 처리

	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		// 큐에서 하나의 원소를 뽑아서 출력
		int x = q.front();
		q.pop();
		cout << x << " ";
		// 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

void DFS(int x) {
	visited[x] = true;
	cout << x << " ";
	// 인접한 노드 사이즈만큼 탐색
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) {	// 방문하지 않았다면
			DFS(y);			// 재귀적으로 방문
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, edge, v;
	cin >> n >> edge >> v;
	for (int i = 0; i < edge; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
		graph[a].push_back(b);
	}

	for (int i = 0; i <= n; i++) {
		if (!graph[i].empty()) {
			sort(graph[i].begin(), graph[i].end());
		}
	}

	DFS(v);
	cout << '\n';
	fill_n(visited, 1001, false);	// 배열을 false로 초기화
	BFS(v);

	return 0;
}