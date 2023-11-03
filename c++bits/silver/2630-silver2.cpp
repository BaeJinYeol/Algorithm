///	
///	색종이 만들기
/// 분할 정복, 재귀
///	

#include <iostream>
#include<utility>
using namespace std;
using ll = long long;

int paper[128][128];
int white = 0;
int blue = 0;

void makeColoredPaper(int x, int y, int n) {
	// 색종이가 모두 같은 색인지 확인
	bool isSameColor = true;
	int color = paper[x][y];

	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (paper[i][j] != color) {
				isSameColor = false;
				break;
			}

	// 모두 같은 색이면 해당 색으로 색종이를 채우고 종료
	if (isSameColor) {
		if (color == 0) white++;
		else blue++;
		return;
	}

	// 모두 같은 색이 아니라면 4분할 하여 재귀 호출
	int half = n / 2;
	makeColoredPaper(x, y, half);				// 좌상단
	makeColoredPaper(x, y + half, half);		// 우상단
	makeColoredPaper(x + half, y, half);		// 좌하단
	makeColoredPaper(x + half, y + half, half);	// 우하단
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