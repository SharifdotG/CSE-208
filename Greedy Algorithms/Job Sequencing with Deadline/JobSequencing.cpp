#include <bits/stdc++.h>

using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool compare(Job job1, Job job2) {
    return job1.profit > job2.profit;
}

void jobScheduling(Job jobs[], int n) {
    sort(jobs, jobs + n, compare);

    int result[n], maxProfit = 0;
    bool slot[n];

    for (int i = 0; i < n; i++) {
        slot[i] = false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;
                slot[j] = true;
                maxProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Maximum profit sequence of jobs: ";
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << jobs[result[i]].id << " ";
        }
    }
    
    cout << endl << "Maximum profit: " << maxProfit << endl;
}

int main() {
    Job jobs[] = {
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
Input:
None

Output:
Maximum profit sequence of jobs: 1 3 4 
Maximum profit: 240
*/