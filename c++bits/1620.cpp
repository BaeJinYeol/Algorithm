#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	unordered_map<string, int> pokeDex;
	vector<string> pokeDexNum(n);

	for (int i = 0; i < n; i++) {
		string poke_name;
		cin >> poke_name;
		pokeDex[poke_name] = i + 1;
		pokeDexNum[i] = poke_name;
	}

	for (int i = 0; i < m; i++) {
		string question;
		cin >> question;

		if (isdigit(question[0])) {
			int num = stoi(question) - 1;
			cout << pokeDexNum[num] << '\n';
		}
		else {
			cout << pokeDex[question] << '\n';
		}
	}

	return 0;
}