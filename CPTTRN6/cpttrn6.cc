// Author: József Farkas
// Github: https://github.com/fjozsef

#include <cstdio>

int main() {
	int num_test_cases;
	int num_lines, num_columns;
	int height, width;

	scanf("%d", &num_test_cases);

	while (num_test_cases--) {
		scanf("%d %d %d %d", &num_lines, &num_columns, &height, &width);

		++height; // plus one line block
		++width;  // plus one column block

		// Block height * block num - 1 (no border on the last block)
		num_lines = height * (num_lines + 1) - 1;
		num_columns = width * (num_columns + 1) - 1 ;
		for (int i = 0; i < num_lines; ++i) {
			for (int j = 0; j < num_columns; ++j) {
				if (i % height != height - 1) {
					if (j % width != width - 1) {
						putchar('.');
					} else {
						putchar('|');
					}
				} else {
					if (j % width != width - 1) {
						putchar('-');
					} else {
						putchar('+');
					}
				}
			}
			putchar('\n');
		}
		if (num_test_cases > 0) {
			putchar('\n');
		}
	}

	return 0;
}
