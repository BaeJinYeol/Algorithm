#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, cur, i;
	cin >> N >> K;

	vector<int> table(N, 1); // 1 ����, 0 ���
	vector<int> dielist;
	cur = 0;

	for (i = 0; i < N; i++) {
		int count = 0;

		// K��° ��� ã��
		while (count < K) {
			cur = (cur + 1) % N;
			if (table[cur] == 1) {
				count++;
			}
		}
		
		// K��° ����� �����ϰ� ������ �߰�
		table[cur] = 0;
		if (cur == 0)
			cur = N;
		dielist.push_back(cur);
	}

	cout << "<" << dielist[0];
	for (i = 1; i < N; i++)
		cout << ", " << dielist[i];
	cout << ">" << '\n';

	return 0;
}