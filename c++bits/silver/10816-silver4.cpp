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
//using namespace std;
// 
//int main()
//{
//	ios::sync_with_stdio(false);
//  cin.tie(NULL);
//
//	int N, M, card, i;
//	vector<int> v;
//
//	cin >> N;
//	for (i = 0; i < N; i++) {
//		cin >> card;
//		v.push_back(card);
//	}
//
//	sort(v.begin(), v.end());
//
//	cin >> M;
//	for (i = 0; i < M; i++) {
//		cin >> card;
//		cout << upper_bound(v.begin(), v.end(), card)
//			- lower_bound(v.begin(), v.end(), card) << ' ';
//	}
//}