// Author: József Farkas
// Github: https://github.com/fjozsef

#include <cstdio>

int main() {
	int num_test_cases;
	int num_lines, num_columns;
	int size;

	scanf("%d", &num_test_cases);

	while (num_test_cases--) {
		scanf("%d %d %d", &num_lines, &num_columns, &size);

		size *= 2;
		num_lines = size * num_lines;
		num_columns = size * num_columns;

		auto diamondPart = [size](int i, int j) {
			bool backslash = true;

			// Mirror to the top right quarter

			// First to the top if needed
			if (i >= size / 2) {
				i = size - i - 1;
				backslash = !backslash;
			}

			// Then to the right if needed
			if (j < size / 2) {
				j = size - j - 1;
				backslash = !backslash;
			}

			// Translate from the top right quarter to the top left quarter to get a \ diagonal
			j -= size / 2;

			// If it's in the diagonal, then it is (back)slash
			if (i == j) {
				return backslash ? '\\' : '/';
			} else {
				return '.';
			}

		};



		for (int i = 0; i < num_lines; ++i) {
			for (int j = 0; j < num_columns; ++j) {
				// Transform to the top left diamond
				putchar(diamondPart(i % size, j % size));
			}
			putchar('\n');
		}
		if (num_test_cases > 0) {
			putchar('\n');
		}

	}

	return 0;
}