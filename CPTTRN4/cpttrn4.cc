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

		++height; // +1 because of the top border
		++width;  // +1 because of the left border
		// Repeat: *.. and the right border: *
		num_lines = height * num_lines + 1;
		num_columns = width * num_columns + 1;
		for (int i = 0; i < num_lines; ++i) {
			for (int j = 0; j < num_columns; ++j) {
				putchar( (i % height == 0 || j % width == 0) ? '*' : '.' );
			}
			putchar('\n');
		}
		if (num_test_cases > 0) {
			putchar('\n');
		}
	}

	return 0;
}