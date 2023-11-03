#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	bool balance;
	cin >> T;
	stack<char> data;
	string bracket;

	for (int i = 0; i < T; i++)
	{
		cin >> bracket;
		balance = true;

		for (char ch : bracket) {
			if (ch == '(')
				data.push(ch);
			else if (ch == ')') {
				if (!data.empty() && data.top() == '(')
					data.pop();
				else {
					balance = false;
					break;
				}
			}
		}
		if (balance && data.empty())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

		while (!data.empty()) data.pop(); // 스텍 초기화
	}

	return 0;
}