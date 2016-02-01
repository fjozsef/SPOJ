// Author: József Farkas
// Github: https://github.com/fjozsef

#include <cstdio>

int main() {
	int num_test_cases;
	char sequence[101];
	int sequence_length;
	char temp;
	bool first;
	scanf("%d\n", &num_test_cases);
	while (num_test_cases--) {
		sequence_length = 0;
		first = true;
		temp = getchar();

		// Store only every second character
		while (temp != '\n') {
			// ATTENTION: There can be extra spaces at the end of the words! (Skip them!)
			if(temp != ' '){
				if (first) {
					sequence[sequence_length] = temp;
					++sequence_length;
				}
				first = !first;
			}
			temp = getchar();
		}

		// Half the sequence length
		sequence_length = (sequence_length + 1) / 2;
		for (int i = 0; i < sequence_length; ++i) {
			putchar(sequence[i]);
		}
		putchar('\n');
	}
	return 0;
}
