#include <iostream>
using namespace std;

/* 
    0은 2와 5의 곱으로 생성됨, 2와 5의 곱의 개수를 세면 0의 개수를 알 수 있음 
    2의 개수는 항상 충분하므로 5의 개수만 카운팅,
    1부터 N까지의 모든 수에서 5의 배수의 개수, 25의 배수의 개수, 125의 배수의 개수,...
    를 모두 더하면 된다.
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
