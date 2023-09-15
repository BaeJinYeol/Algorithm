#include <iostream>
#include <deque>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, second;
	cin >> N;

	deque<int> deck;

	for (int i = 1; i <= N; i++)
		deck.push_back(i);

	while (deck.size() != 1) {
		// ù ��° ��� ����
		deck.pop_front();

		// �� ��° ��� �޾Ƽ� �� �ڷ�
		second = deck.front();
		deck.pop_front();
		deck.push_back(second);
	}
	cout << deck.front();

	return 0;
}