///	
///	Z
/// 분할 정복, 재귀
/// 

#include <iostream>
using namespace std;

int n, r, c, times;

void search_z(int x, int y, int size) {
	if (size == 1) {
		if (x == r && y == c) {
			cout << times << '\n';
			exit(0);
		}
		times++;
		return;
	}

	int half = size / 2;
	if (r < x + half && c < y + half) {
		search_z(x, y, half);					// 좌상단
	}
	else if (r < x + half && c >= y + half) {
		times += half * half;
		search_z(x, y + half, half);			// 우상단
	}
	else if (r >= x + half && c < y + half) {
		times += 2 * half * half;
		search_z(x + half, y, half);			// 좌하단
	}
	else {
		times += 3 * half * half;
		search_z(x + half, y + half, half);		// 우하단
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> r >> c;
	times = 0;
	int size = 1 << n;		// 2^n을 계산

	search_z(0, 0, size);

	return 0;
}