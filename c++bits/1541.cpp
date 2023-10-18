#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	vector<int> nums;
	vector<char> opers;
	cin >> str;
	string num = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] < 48) {
			opers.push_back(str[i]);
			nums.push_back(stoi(num));
			num.clear();
		}
		else {
			num.push_back(str[i]);
		}
	}
	nums.push_back(stoi(num));
	
	if (nums.size() > 1) { // 숫자 하나만 들어오는 경우 제외
		for (int i = 0; i < opers.size() - 1; i++)
			if (opers[i] == '-' && opers[i + 1] == '+')
				opers[i + 1] = '-';
	}

	int sum = nums[0];
	for (int i = 0; i < opers.size(); i++) {
		if (opers[i] == '-')
			sum -= nums[i + 1];
		else
			sum += nums[i + 1];
	}

	cout << sum << '\n';
	return 0;
}