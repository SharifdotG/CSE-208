#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Job {
    char id;
    int deadline, profit;
};

int compare(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

void jobScheduling(struct Job jobs[], int n) {
    qsort(jobs, n, sizeof(struct Job), compare);

    int result[n], maxProfit = 0;
    int slot[n];

    for (int i = 0; i < n; i++) {
        slot[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = fmin(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                result[j] = i;
                slot[j] = 1;
                maxProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Maximum profit sequence of jobs: ");
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            printf("%c ", jobs[result[i]].id);
        }
    }
    
    printf("\nMaximum profit: %d\n", maxProfit);
}

int main() {
    struct Job jobs[] = {
        {'1', 2, 90},
        {'2', 1, 80},
        {'3', 2, 100},
        {'4', 3, 50},
        {'5', 1, 40}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);
    
    jobScheduling(jobs, n);

    return 0;
}

/*
Output:
Maximum profit sequence of jobs: 1 3 4 
Maximum profit: 240
*/