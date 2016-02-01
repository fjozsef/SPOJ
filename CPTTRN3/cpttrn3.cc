// Author: József Farkas
// Github: https://github.com/fjozsef

#include <cstdio>

int main() {
	int num_test_cases;
	int num_lines, num_columns;

	scanf("%d", &num_test_cases);

	while (num_test_cases--) {
		scanf("%d %d", &num_lines, &num_columns);

		// Repeat: *.. and the right border: *
		num_lines = 3 * num_lines + 1;
		num_columns = 3 * num_columns + 1;
		for (int i = 0; i < num_lines; ++i) {
			for (int j = 0; j < num_columns; ++j) {
				putchar( (i % 3 == 0 || j % 3 == 0) ? '*' : '.' );
			}
			putchar('\n');
		}
		if (num_test_cases > 0) {
			putchar('\n');
		}
	}

	return 0;
}