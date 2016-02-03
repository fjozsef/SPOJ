// Author: József Farkas
// Github: https://github.com/fjozsef

#include <cstdio>

int main() {
	int num_test_cases;
	int n, x, y;
	scanf("%d", &num_test_cases);
	bool need_space;
	while (num_test_cases--) {
		need_space = false;
		scanf("%d %d %d", &n, &x, &y);
		for (int i = x; i < n; i += x) {
			if (i % y != 0) {
				if (need_space) {
					putchar(' ');
				} else {
					need_space = true;
				}
				printf("%d", i);
			}
		}
		putchar('\n');
	}
	return 0;
}