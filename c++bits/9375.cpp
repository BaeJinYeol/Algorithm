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

	// 각 종류별 의상의 수를 곱하여 경우의 수 계산
	for (const string& kind : kindOfClothes) {
		clothes_case *= (closet[kind].size() + 1);  // 각 종류별 의상 수에 아무것도 선택안할경우를 더한 값을 곱함
	}

	// 아무 의상도 선택하지 않는 경우(빈 상태)는 제외하므로 1을 빼줌
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