///	
///	수학, 문자열
/// 

#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<string> strv(3);
	for (string& s : strv) cin >> s;
	int num;

	if (strv[0][2] != 'z')
		num = stoi(strv[0]) + 3;
	else if (strv[1][2] != 'z')
		num = stoi(strv[1]) + 2;
	else
		num = stoi(strv[2]) + 1;

	if (num % 15 == 0) {
		cout << "FizzBuzz";
	}
	else if (num % 3 == 0) {
		cout << "Fizz";
	}
	else if (num % 5 == 0) {
		cout << "Buzz";
	}
	else {
		cout << num;
	}

	return 0;
}