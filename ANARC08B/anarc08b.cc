// Author: József Farkas
// Github: https://github.com/fjozsef

#include <cstdio>
#include <algorithm>
#include <cstring>

const int kNumLength = 91; // log_2 (10^9) ~ 30 digit. Each digit written uses 3 decimal places. +1 '\0' terminating character


class Number {
public:
	char display_code[kNumLength];
	int length;


	Number(): length(0) {
		display_code[0] = 0;
	}

	Number(int integer) : length(0) {
		display_code[0] = 0;
		if (integer == 0) {
			strcpy(display_code, Number::convertDigit(0));
		}
		const char *digit;
		while (integer != 0) {
			digit = Number::convertDigit(integer % 10);
			integer /= 10;
			display_code[length] = digit[2];
			++length;
			display_code[length] = digit[1];
			++length;
			display_code[length] = digit[0];
			++length;
		}
		display_code[length] = 0;

		std::reverse(display_code, display_code + length);
	}

	int getInt() {
		int number = 0;
		for (char *c = display_code; *c != 0; c += 3) {
			number *= 10;
			number += Number::convertDigit(c[0], c[1], c[2]);
		}
		return number;
	}

	// 0 -> 0111111 -> 063
	// 1 -> 0001010 -> 010
	// 2 -> 1011101 -> 093
	// 3 -> 1001111 -> 079
	// 4 -> 1101010 -> 106
	// 5 -> 1100111 -> 103
	// 6 -> 1110111 -> 119
	// 7 -> 0001011 -> 011
	// 8 -> 1111111 -> 127
	// 9 -> 1101011 -> 107

	static int convertDigit(char a, char b, char c) {
		if (a == '0') {
			if (b == '1') {
				if (c == '0') {
					return 1;
				} else {
					return 7;
				}
			} else if ( b == '6') {
				return 0;
			} else if ( b == '7') {
				return 3;
			} else {
				return 2;
			}
		} else {
			if (b == '0') {
				if (c == '3') {
					return 5;
				} else if (c == '6') {
					return 4;
				} else {
					return 9;
				}

			} else if (b == '1') {
				return 6;
			} else {
				return 8;
			}
		}
	}

	static const char* convertDigit(int integer) {
		static const char* digit[10] = {"063", "010", "093", "079", "106", "103", "119", "011", "127", "107" };
		return digit[integer];
	}
};

int main() {
	Number a, b, c;
	while (true) {
		a.length = b.length = 0;
		a.display_code[0] = getchar();
		if (a.display_code[0] == 'B') break;
		a.length = 1;
		while (true) {
			a.display_code[a.length] = getchar();
			if (a.display_code[a.length] == '+') {
				a.display_code[a.length] = 0;
				break;
			}
			++a.length;
		}
		while (true) {
			b.display_code[b.length] = getchar();
			if (b.display_code[b.length] == '=') {
				b.display_code[b.length] = 0;
				break;
			}
			++b.length;
		}
		getchar(); // skip '\n'
		c = a.getInt() + b.getInt();
		printf("%s+%s=%s\n", a.display_code, b.display_code, c.display_code);
	}
	return 0;
}
