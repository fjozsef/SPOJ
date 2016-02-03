// Author: József Farkas
// Github: https://github.com/fjozsef

#include <cstdio>

int main() {
	int num_test_cases;
	int num_tuples;
	char tuples[100][7];
	char alphabet[65];
	int index;

	scanf("%d", &num_test_cases);
	while (num_test_cases--) {
		scanf("%d\n", &num_tuples);
		for (int i = 0; i < num_tuples; ++i) {
			scanf("%s", tuples[i]);
		}
		scanf("%s", alphabet);

		for (int i = 0; i < num_tuples; ++i) {
			// Get the first letter
			index = 0;
			for (int j = 0; j < 6; ++j) {
				index |= tuples[i][j] & (1 << j);
			}
			printf("%c", alphabet[index]);

			// Get the second letter
			index = 0;
			for (int j = 0; j < 3; ++j) {
				index |= (tuples[i][j] & (1 << (j + 3))) >> 3 ;
			}
			for (int j = 3; j < 6; ++j) {
				index |= (tuples[i][j] & (1 << (j - 3))) << 3;
			}
			printf("%c", alphabet[index]);
		}
		printf("\n");
	}

	return 0;
}
