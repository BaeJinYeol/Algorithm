///	
///	������ �����
/// ���� ����, ���
///	

#include <iostream>
#include<utility>
using namespace std;
using ll = long long;

int paper[128][128];
int white = 0;
int blue = 0;

void makeColoredPaper(int x, int y, int n) {
	// �����̰� ��� ���� ������ Ȯ��
	bool isSameColor = true;
	int color = paper[x][y];

	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (paper[i][j] != color) {
				isSameColor = false;
				break;
			}

	// ��� ���� ���̸� �ش� ������ �����̸� ä��� ����
	if (isSameColor) {
		if (color == 0) white++;
		else blue++;
		return;
	}

	// ��� ���� ���� �ƴ϶�� 4���� �Ͽ� ��� ȣ��
	int half = n / 2;
	makeColoredPaper(x, y, half);				// �»��
	makeColoredPaper(x, y + half, half);		// ����
	makeColoredPaper(x + half, y, half);		// ���ϴ�
	makeColoredPaper(x + half, y + half, half);	// ���ϴ�
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];

	makeColoredPaper(0, 0, n);

	cout << white << '\n' << blue << '\n';

	return 0;
}