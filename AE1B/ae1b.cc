// Author: József Farkas
// Github: https://github.com/fjozsef

#include <cstdio>
#include <algorithm>

int main() {
	int num_boxes;
	int num_screws_per_table;
	int num_tables;
	int num_screws[1000];
	scanf("%d %d %d\n", &num_boxes, &num_screws_per_table, &num_tables);
	int screws_needed = num_screws_per_table * num_tables;
	for (int i = 0; i < num_boxes; ++i) {
		scanf("%d", &num_screws[i]);
	}
	std::sort(num_screws, num_screws + num_boxes, [](int i, int j){ return j < i; });
	int boxes_needed = 0;
	while (screws_needed > 0) {
		screws_needed -= num_screws[boxes_needed];
		++boxes_needed;
	}
	printf("%d\n", boxes_needed);
	return 0;
}