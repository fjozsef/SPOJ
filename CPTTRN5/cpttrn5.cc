// Author: József Farkas
// Github: https://github.com/fjozsef

#include <cstdio>

int main() {
	int num_test_cases;
	int num_lines, num_columns;
	int width;

	scanf("%d", &num_test_cases);

	while (num_test_cases--) {
		scanf("%d %d %d", &num_lines, &num_columns, &width);

		++width;  // +1 because of the left border
		// Repeat: *.. and the right border: *
		num_lines = width * num_lines + 1;
		num_columns = width * num_columns + 1;
		for (int i = 0; i < num_lines; ++i) {
			for (int j = 0; j < num_columns; ++j) {
				if (i % width == 0 || j % width == 0) {
					putchar('*');
				} else {

					// If it's even then \ diagonal
					if ( (i / width + j / width) % 2 == 0 ) {
						putchar((i % width == j % width) ? '\\' : '.');
					}
					// Else it's / diagonal
					else {
						putchar((i % width == width - (j % width)) ? '/' : '.');
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