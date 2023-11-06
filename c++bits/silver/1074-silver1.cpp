///	
///	Z
/// ���� ����, ���
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
		search_z(x, y, half);					// �»��
	}
	else if (r < x + half && c >= y + half) {
		times += half * half;
		search_z(x, y + half, half);			// ����
	}
	else if (r >= x + half && c < y + half) {
		times += 2 * half * half;
		search_z(x + half, y, half);			// ���ϴ�
	}
	else {
		times += 3 * half * half;
		search_z(x + half, y + half, half);		// ���ϴ�
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> r >> c;
	times = 0;
	int size = 1 << n;		// 2^n�� ���

	search_z(0, 0, size);

	return 0;
}