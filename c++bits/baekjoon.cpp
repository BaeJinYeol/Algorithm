#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
using ll = long long;

bool compare(string a, string b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<string> v;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (find(v.begin(), v.end(), str) == v.end())
			v.push_back(str);
	}

	sort(v.begin(), v.end(), compare);

	for (string str : v) 
		cout << str << '\n';

	return 0;
}