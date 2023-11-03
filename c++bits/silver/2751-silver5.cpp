#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, i;
	cin >> N;
	vector<int> nums(N);
	for (i = 0; i < N; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());

	for (int num : nums)
		cout << num << '\n';

	return 0;
}