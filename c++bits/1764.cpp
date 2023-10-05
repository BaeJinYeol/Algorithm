#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	unordered_map<string, bool> not_hear;
	vector<string> not_hear_see;

	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		not_hear.insert(make_pair(name, true));
	}

	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		
		if (not_hear[name]) {
			not_hear_see.push_back(name);
		}
	}

	sort(not_hear_see.begin(), not_hear_see.end());
	cout << not_hear_see.size() << '\n';
	for (string name : not_hear_see)
		cout << name << '\n';

	return 0;
}