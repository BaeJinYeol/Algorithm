#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	int N, M, i, j, input, check;
	cin >> N;
	vector<int> A(N);
	for (i = 0; i < N; i++)
		cin >> A[i];
	cin >> M;
	sort(A.begin(), A.end());

	for (i = 0; i < M; i++) {
		cin >> input;

		bool check = binary_search(A.begin(), A.end(), input);

		cout << check << '\n';
	}

	return 0;
}