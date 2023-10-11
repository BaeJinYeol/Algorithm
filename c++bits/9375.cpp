#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

void ootd(int n) {
	int clothes_case = 1;
	map<string, vector<string>> closet;
	vector<string> kindOfClothes;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		closet[b].push_back(a);

		if (find(kindOfClothes.begin(), kindOfClothes.end(), b) == kindOfClothes.end()) {
			kindOfClothes.push_back(b);
		}

	}

	// �� ������ �ǻ��� ���� ���Ͽ� ����� �� ���
	for (const string& kind : kindOfClothes) {
		clothes_case *= (closet[kind].size() + 1);  // �� ������ �ǻ� ���� �ƹ��͵� ���þ��Ұ�츦 ���� ���� ����
	}

	// �ƹ� �ǻ� �������� �ʴ� ���(�� ����)�� �����ϹǷ� 1�� ����
	clothes_case--;

	cout << clothes_case << endl;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testcase;
	cin >> testcase;

	while (testcase--) {
		int n;
		cin >> n;
		ootd(n);
	}
	return 0;
}