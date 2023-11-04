///	
///	연결 요소의 개수
/// 그래프 이론, 그래프 탐색
/// 깊이 우선 탐색 사용
/// 

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;	// 인접 리스트 그래프
bool visited[1001];			// 방문 여부 체크

void DFS(int node) {
	visited[node] = true;
	for (int neighbor : graph[node]) {
		if (!visited[neighbor]) {
			DFS(neighbor);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int vertexN, edgeM;
	cin >> vertexN >> edgeM;

	graph.resize(vertexN + 1);	// 벡터 크기 재설정

	for (int i = 0; i < edgeM; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);	// 양 방향으로 저장
	}

	int link_n = 0;

	for (int i = 1; i <= vertexN; i++) {
		if (!visited[i]) {
			DFS(i);
			link_n++;
		}
	}

	cout << link_n << '\n';

	return 0;
}