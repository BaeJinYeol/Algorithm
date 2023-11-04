///	
///	���� ����� ����
/// �׷��� �̷�, �׷��� Ž��
/// ���� �켱 Ž�� ���
/// 

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;	// ���� ����Ʈ �׷���
bool visited[1001];			// �湮 ���� üũ

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

	graph.resize(vertexN + 1);	// ���� ũ�� �缳��

	for (int i = 0; i < edgeM; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);	// �� �������� ����
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