// Author: József Farkas
// Github: https://github.com/fjozsef

#include <cstdio>

template <int sizeX, int sizeY>
class Matrix {
public:
	int** array;

	Matrix() {
		array = new int*[sizeX];
		for (int i = 0; i < sizeX; ++i) {
			array[i] = new int[sizeY];
		}
	}

	~Matrix(){
		for(int i=0;i<sizeX;++i){
			delete[] array[i];
		}
		delete[] array;
	}

	int* operator[](int index) {
		return array[index];
	}

};



int main() {
	const int kMaxFriend = 100;
	const int kMaxApple = 100;
	const int kMaxPrice = 1000;
	int num_test_cases;
	int num_friends;
	int apple_kg;
	int& num_packages = apple_kg; // Number of packages are equals to the number of apples needed
	int package_prices[kMaxApple + 1];

	Matrix < kMaxFriend + 1, kMaxApple + 1 > * DP = new Matrix < kMaxFriend + 1, kMaxApple + 1 > [kMaxPrice + 1];

	scanf("%d", &num_test_cases);
	while (num_test_cases--) {
		scanf("%d %d", &num_friends, &apple_kg);
		package_prices[0] = 0;
		for (int i = 1; i <= num_packages; ++i) {
			scanf("%d", &package_prices[i]);
		}

		for (int i = 0; i <= num_friends; ++i) {
			for (int k = 0; k <= num_packages; ++k) {
				DP[i][0][k] = 0;  // 0 kg needed, so it's free
			}
			for (int k = 1; k <= apple_kg; ++k) {
				DP[i][k][0] = -1; // need apple, but no package
			}
		}

		for (int i = 0; i <= num_friends; ++i) {
			for (int j = 1; j <= apple_kg; ++j) {
				for (int k = 1; k <= num_packages; ++k) {
					DP[i][j][k] = -1;
					// We still can buy a package and we could have the 'k' kg package and the smaller solution is valid
					if (i > 0 && j >= k && package_prices[k] >= 0 && DP[i - 1][j - k][k] != -1) {
						DP[i][j][k] = DP[i - 1][j - k][k] + package_prices[k];
					}

					// If we have no solution yet or if we choose from only the first k-1 packages is better
					if (DP[i][j][k] == -1 || (DP[i][j][k - 1] != -1 && DP[i][j][k] > DP[i][j][k - 1])) {
						DP[i][j][k] = DP[i][j][k - 1];
					}

				}
			}
		}

		printf("%d\n", DP[num_friends][apple_kg][num_packages]);
	}

	delete[] DP;
	return 0;
}
