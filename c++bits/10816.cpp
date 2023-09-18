#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, i, card;
	cin >> N;
	vector<int> sangCards(20000000, 0);
	for (i = 0; i < N; i++) {
		cin >> card;
		sangCards[card + 10000000]++;
	}

	cin >> M;
	vector<int> getCards(M);
	for (i = 0; i < M; i++)
		cin >> getCards[i];

	for (int card : getCards)
		cout << sangCards[card + 10000000] << ' ';

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main()
//{
//	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//
//	int N, M, n;
//	std::vector<int> v;
//
//	std::cin >> N;
//	while (N--)
//	{
//		std::cin >> n;
//		v.push_back(n);
//	}
//
//	std::sort(v.begin(), v.end());
//
//	std::cin >> M;
//	while (M--)
//	{
//		std::cin >> n;
//		std::cout << std::upper_bound(v.begin(), v.end(), n)
//			- std::lower_bound(v.begin(), v.end(), n) << ' ';
//	}
//}