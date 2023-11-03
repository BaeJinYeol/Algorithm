#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

void triangle(int n) {
	vector<ll> side_len(101); // 크기를 n+1로 주면 메모리 초과 뜸
	side_len[1] = side_len[2] = side_len[3] = 1;
	side_len[4] = side_len[5] = 2;

	for (int i = 6; i <= n; i++)
		side_len[i] = side_len[i - 1] + side_len[i - 5];

	cout << side_len[n] << endl;
}

int main() {
	int test_case, n;
	cin >> test_case;

	while (test_case--) {
		cin >> n;
		triangle(n);
	}
	return 0;
}