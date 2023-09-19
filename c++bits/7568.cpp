#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, count;
	cin >> N;
	vector<pair<int, int>> bodys(N);

	for (int i = 0; i < N; i++)
		cin >> bodys[i].first >> bodys[i].second;

	for (int j = 0; j < N; j++) {
		count = 1;
		for (int k = 0; k < N; k++)
			if (bodys[j].first < bodys[k].first && 
				bodys[j].second < bodys[k].second)
				count++;
		cout << count << ' ';
	}


	return 0;
}