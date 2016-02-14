// Author: József Farkas
// Github: https://github.com/fjozsef

#include <cstdio>

int main() {
	char input[2001];
	int diff_opening_and_closing_braces;
	int num_change;
	for (int i = 1; ; ++i) {
		scanf("%s", input);
		if (input[0] == '-') break;
		diff_opening_and_closing_braces = 0;
		num_change = 0;
		// Iterate over the braces
		for (char* c = input; *c != 0; ++c) {
			if (*c == '}') {
				if (diff_opening_and_closing_braces <= 0) { // must convert to opening brace
					++num_change;
				} else { // It's okay if it remains closing brace
					--diff_opening_and_closing_braces;
					continue;
				}
			}
			++diff_opening_and_closing_braces; // One more opening brace
		}
		// We have to convert the second half of the opening braces to closing braces to make their num equal
		num_change += diff_opening_and_closing_braces / 2; 
		printf("%d. %d\n", i, num_change);
	}
	return 0;
}
