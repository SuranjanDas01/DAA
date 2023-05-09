//by SURANJAN DAS

#include <stdio.h>
#include <stdlib.h>

// structure for an activity
struct activity {
    int start, finish;
};

// comparison function to sort activities by finish time
int cmpfunc(const void* a, const void* b) {
    struct activity* act1 = (struct activity*) a;
    struct activity* act2 = (struct activity*) b;
    return act1->finish - act2->finish;
}

// function to find the maximum set of mutually compatible activities
void activitySelection(struct activity activities[], int n) {
    // sort the activities by their finish times in non-decreasing order
    qsort(activities, n, sizeof(struct activity), cmpfunc);

    // select the first activity as the current activity and add it to the set of selected activities
    int current = 0;
    printf("Selected activities:\n");
    printf("(%d, %d)\n", activities[current].start, activities[current].finish);

    // for each remaining activity, if its start time is after or equal to the finish time of the current activity,
    // add it to the set of selected activities and set it as the current activity
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= activities[current].finish) {
            printf("(%d, %d)\n", activities[i].start, activities[i].finish);
            current = i;
        }
    }
}

int main() {
    // sample input
    struct activity activities[] = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    int n = sizeof(activities) / sizeof(activities[0]);

    activitySelection(activities, n);

    return 0;
}
