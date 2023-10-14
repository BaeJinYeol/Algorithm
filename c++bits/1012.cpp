#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(vector<vector<int>>& field, vector<vector<bool>>& visit, int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visit[x][y] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx >= 0 && nx < field.size() && ny >= 0 && ny < field[0].size()) {
				if (!visit[nx][ny] && field[nx][ny] == 1) {
					q.push({ nx, ny });
					visit[nx][ny] = true;
				}
			}
		}
	}
}

int minCabbageWorm(vector<vector<int>>& field)
{
	int worm = 0;
	int n = field.size();
	int m = field[0].size();
	vector<vector<bool>> visit(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visit[i][j] && field[i][j] == 1) {
				bfs(field, visit, i, j);
				worm++;
			}
	return worm;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		int m, n, k;
		cin >> m >> n >> k;

		vector<vector<int>> field(n, vector<int>(m, 0));

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;  // 주의: 입력 순서가 y, x로 바뀜
		}

		cout << minCabbageWorm(field) << '\n';
	}

	return 0;
}