// Author: József Farkas
// Github: https://github.com/fjozsef

#include <cstdio>
#include <algorithm>

int main() {
	int num_test_cases;
	int size_of_shape;
	int i, j;
	scanf("%d", &num_test_cases);
	bool reverse;
	while (num_test_cases--) {
		scanf("%d", &size_of_shape);


		// For every row 
		for (i = 0; i < size_of_shape; ++i) {
			// A row is divided into 3 parts (parts can be empty)

			// This is the first part, where . and * alternates, how far it depends on the distance from the "middle"
			for (j = 0; j < (size_of_shape - 1) / 2 - std::abs(((size_of_shape + 1) / 2 - i)) ; ++j) {
				putchar(j % 2 ? '.' : '*');
			}

			// Second part
			// If size of the shape is even and the row index is above the half, then *** and ... rows are switched
			reverse = false;
			if (size_of_shape % 2 == 0 && i > (size_of_shape + 1) / 2) {
				reverse = true;
			}

			for (; j < (size_of_shape + 1 ) / 2  + std::abs((size_of_shape / 2 - i)); ++j) {
				// There was a mistake in the center and I corrigated that here, instead of * now it's .
				if (size_of_shape % 2 == 0 && (i - 1) == j && j == (size_of_shape) / 2 - 1) {
					putchar('.');
					continue;
				}

				// Do the reverse if needed and put * or .
				if ( (reverse ? i + 1 : i) % 2 == 0) {
					putchar('*');
				} else {
					putchar('.');
				}
			}

			// The third part
			for (; j < size_of_shape; ++j) {
				putchar((j + size_of_shape) % 2 ? '*' : '.');
			}
			putchar('\n');
		}

		if (num_test_cases > 0) {
			putchar('\n');
		}
	}
	return 0;
}