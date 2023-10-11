#include <iostream>
#include <vector>
using namespace std;

void SumMethod(int n) {
	int sum = 0;
	vector<int> method(12,0);

	method[1] = 1;
	method[2] = 2;
	method[3] = 4;
	for (int i = 4; i <= n; i++)
		method[i] = method[i - 1] + method[i - 2] + method[i - 3];

	cout << method[n] << endl;
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
		SumMethod(n);
	}

	return 0;
}