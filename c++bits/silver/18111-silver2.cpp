#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, b;
	int height, time = INT_MAX - 1;
	cin >> n >> m >> b;

	vector<vector<int>> ground(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ground[i][j];
	
	for (int k = 0; k <= 256; k++) {
		int sum = 0, tmp = b;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// 블럭 꺼내 놓는다
				if (ground[i][j] < k) {
					sum += k - ground[i][j];
					tmp -= k - ground[i][j];
				} // 블록 제거
				else if (ground[i][j] > k) {
					sum += (ground[i][j] - k) * 2;
					tmp += ground[i][j] - k;
				} // 연산 X
				else {
					continue;
				}
			}
		}

		if (tmp >= 0) {
			if (sum <= time) {
				time = sum;
				height = k;
			}
		}
	}

	cout << time << ' ' << height << '\n';

	return 0;
}