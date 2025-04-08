#include <iostream>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, T, P;
	int S, M, L, XL, XXL, XXXL;
	int max = 0;
	int size[6];

	cin >> N;
	for (int& i : size) cin >> i;
	cin >> T >> P;
	
	int count = 0;
	for (int i : size) {
		if (i == 0) continue;
		if (i % T != 0) count += i / T + 1;
		else count += i / T;
	}

	cout << count << endl;
	cout << N / P << ' ' << N % P;

	return 0;
}