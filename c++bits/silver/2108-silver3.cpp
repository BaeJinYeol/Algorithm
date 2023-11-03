#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int RANGE = 8001; // 범위: -4000 ~ 4000

int mode(vector<int> frequency) 
{
	int flag;
	int max = 0;

	for (int i = 0; i < RANGE; i++) {
		if (frequency[i] > max) {
			max = frequency[i];
			flag = i;
		}
	}
	for (int i = flag + 1; i < RANGE; i++) {
		if (frequency[i] == max) {
			flag = i;
			break;
		}
	}
	return flag - 4000;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	double sum = 0;
	cin >> n;

	vector<int> input(n);
	vector<int> frequency(RANGE, 0);

	for (int i = 0; i < n; i++) {
		cin >> input[i];
		sum += input[i];
		frequency[input[i] + 4000]++;
	}

	sort(input.begin(), input.end());

	// 산술평균, 중앙값, 최빈값, 범위
	cout << int(round(sum / n)) << '\n';
	cout << input[(n - 1) / 2] << '\n';
	cout << mode(frequency) << '\n';
	cout << input.back() - input.front() << '\n';

	return 0;
}