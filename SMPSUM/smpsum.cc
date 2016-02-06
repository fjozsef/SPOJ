// Author: József Farkas
// Github: https://github.com/fjozsef

#include <cstdio>

inline int sumOfSquares(int n) {
	return n * (n + 1) * (2 * n + 1) / 6;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", sumOfSquares(b) - sumOfSquares(a - 1));
	return 0;
}