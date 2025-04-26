#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	pair<int, int> start;

	vector<vector<bool>> visited(n, vector<bool>(m, false));
	vector<vector<int>> dist(n, vector<int>(m, -1));

	int a;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a;
			arr[i][j] = a;
			if (a == 2) start = { i,j };
		}
	
	queue<pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = true;
	dist[start.first][start.second] = 0;

	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny]) continue;
			if (arr[nx][ny] == 0) continue;

			visited[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx, ny });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) cout << "0 ";
			else if (visited[i][j]) cout << dist[i][j] << ' ';
			else cout << "-1 ";
		}
		cout << '\n';
	}

	return 0;
}