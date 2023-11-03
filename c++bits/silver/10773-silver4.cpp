#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int K, cur;
	cin >> K;
	stack<int> st;

	for (int i = 0; i < K; i++) {
		cin >> cur;
		if (cur == 0 && !st.empty()) st.pop();
		else st.push(cur);
	}

	int sum = 0;
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}

	cout << sum << '\n';

	return 0;
}