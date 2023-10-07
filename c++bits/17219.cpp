#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, string> password;

	for (int i = 0; i < n; i++) {
		string site, pass;
		cin >> site >> pass;
		password.insert(make_pair(site, pass));
	}

	for (int i = 0; i < m; i++) {
		string site;
		cin >> site;
		cout << password[site] <<'\n';
	}

	return 0;
}