#include <iostream>
#include <string>
using namespace std;

int FindTitle(int N) 
{
	int i = 666, count = 0;
	string series;

	while (1) {
		series = to_string(i);
		for (int j = 0; j < series.length() - 2; j++) {
			if (series[j] == '6' && series[j + 1] == '6' && series[j + 2] == '6') {
				count++;
				if (count == N)
					return i;
				break;
			}
		}
		i++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	
	cout << FindTitle(N);

	return 0;
}