// Author: József Farkas
// Github: https://github.com/fjozsef

#include <cstdio>

static const int kMaxFamilySize = 1000;
static const int kMaxCapacity = 1000;

class Group {
public:
	int weight;		// Weight of the group
	int size;		// Size of the group
	Group* parent;	// If the parent == nullptr then this the Head of the Group and this identifies the Group, otherwise it's getHead()

	Group()
		: weight(0),
		  size(0),
		  parent(nullptr)
	{ }

	void join(Group& other) {
		Group *headA = getHead();
		Group *headB = other.getHead();
		if (headA == headB) return;
		headB->parent = headA;
		headA->size += headB->size;
		headA->weight += headB->weight;
		return;
	}

	Group* getHead() {
		Group* head = this;
		while (head->parent != nullptr) {
			head = head->parent;
		}
		return head;
	}

};


int main() {

	int num_family_members;
	int capacity;

	// We allocate the maximum number of groups to avoid dynamic allocation, which is slower.
	Group groups[kMaxFamilySize];

	int num_liked_groups, liked_group;

	// Subsolutions for the knapsack problem
	// problem[i][c] is the maximal value we can reach if we want to choose from the the first i item to put into the knapsack with capacity c
	int problem[kMaxFamilySize + 1][kMaxCapacity + 1];

	while (true) {
		scanf("%d %d", &num_family_members, &capacity);
		if (num_family_members == 0) break;

		// Create group for each Group
		for (int i = 0; i < num_family_members; ++i) {
			scanf("%d", &(groups[i].weight));
			groups[i].size = 1;
			groups[i].parent = nullptr;
		}

		// Process the likes
		for (int i = 0; i < num_family_members; ++i) {
			scanf("%d", &num_liked_groups);
			for (int j = 0; j < num_liked_groups; ++j) {
				scanf("%d", &liked_group);
				--liked_group; // Change index to start from 0
				Group& headA = *groups[i].getHead();
				Group& headB = *groups[liked_group].getHead();
				headA.join(headB);
			}
		}

		int empty_group_index = 0;

		auto findNextEmptyGroup = [&groups, &empty_group_index, num_family_members] () {
			while (groups[empty_group_index].parent == nullptr && empty_group_index < num_family_members) ++empty_group_index;
		};
		findNextEmptyGroup();

		// Move the groups from backwards to the front to fill the empty groups
		for (int j = num_family_members - 1; j >= 0; --j) {
			if (j < empty_group_index) break;
			if (groups[j].size == 0) continue;
			groups[empty_group_index] = groups[j];
			groups[j].parent = &groups[empty_group_index];
			findNextEmptyGroup();
		}

		// We just have to solve a knapsack problem

		// Initalization
		// If we have no group then the value is 0 and it's independent from the capacity
		for (int c = 0; c <= capacity; ++c) {
			problem[0][c] = 0;
		}

		// A group is either goes to the ride or not, it depends on which is better
		for (int i = 1; i <= empty_group_index; ++i) {
			for (int c = 0; c <= capacity; ++c) {
				problem[i][c] = problem[i - 1][c];

				//if it fits
				if (groups[i - 1].weight <= c) {
					int value = problem[i - 1][c - groups[i - 1].weight] + groups[i - 1].size;
					if (value > problem[i][c]) {
						problem[i][c] = value;
					}
				}
			}
		}

		printf("%d\n", problem[empty_group_index][capacity]);
	}
	return 0;
}
