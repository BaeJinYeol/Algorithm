#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, cut;
	cin >> n;
	vector<int> eval(n);

	if (n == 0)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) 
		cin >> eval[i];

	sort(eval.begin(), eval.end());

	cut = round(n * 0.15);
	double sum = 0;
	for (int i = cut; i < n - cut; i++)
		sum += eval[i];

	cout << (int)round(sum / (n - (cut * 2)));

	return 0;
}