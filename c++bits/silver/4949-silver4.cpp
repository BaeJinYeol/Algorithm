#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool balanceWorld(string line)
{
	stack<char> st;
	bool flag = true;

	for (int i = 0; i < line.length(); i++) {
		char ch = line[i];
		
		if (ch == '(' || ch == '[') { st.push(ch); }
		else if (ch == ')') {
			if (!st.empty() && st.top() == '(') { st.pop(); }
			else { 
				flag = false;
				break;
			}
		}
		else if (ch == ']') {
			if (!st.empty() && st.top() == '[') { st.pop(); }
			else {
				flag = false;
				break;
			}
		}
	}

	if (flag && st.empty()) return true;
	else return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string line;

	while (1) {
		line.clear();
		getline(cin, line);

		if (!line.compare(".")) { break; }

		if (balanceWorld(line)) { cout << "yes" << '\n'; }
		else { cout << "no" << '\n'; }
	}
	return 0;
}