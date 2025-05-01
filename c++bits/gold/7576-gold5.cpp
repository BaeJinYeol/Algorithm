#include <iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;

	cin >> m >> n;

	vector<vector<int>> box(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> box[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (box[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] = true;
			}

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	while (!q.empty()) {
		pair<int,int> xy = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = xy.first + dx[dir];
			int ny = xy.second + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny]) continue;
			if (box[nx][ny] == -1) continue;

			visited[nx][ny] = true;
			box[nx][ny] = box[xy.first][xy.second] + 1;
			q.push({ nx,ny });
		}
	}

	int day = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
			day = max(day, box[i][j]);
		}
	cout << day - 1 << '\n';
	return 0;
}