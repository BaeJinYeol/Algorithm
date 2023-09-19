#include <iostream>
using namespace std;

/* 
    0�� 2�� 5�� ������ ������, 2�� 5�� ���� ������ ���� 0�� ������ �� �� ���� 
    2�� ������ �׻� ����ϹǷ� 5�� ������ ī����,
    1���� N������ ��� ������ 5�� ����� ����, 25�� ����� ����, 125�� ����� ����,...
    �� ��� ���ϸ� �ȴ�.
*/
int countZerosInFactorial(int n) {
    int countZeros = 0;
    for (int i = 5; n / i >= 1; i *= 5) {
        countZeros += n / i;
    }
    return countZeros;
}

int main() {
    int N;
    cin >> N;

    int result = countZerosInFactorial(N);

    cout << result;

    return 0;
}
