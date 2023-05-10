//by SURANJAN DAS
#include <stdio.h>
#include <stdlib.h>

// Function to sort the jobs in decreasing order of their profits
void sort_jobs_by_profit(int deadlines[], int profits[], int n) {
    int i, j, temp_deadline, temp_profit;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (profits[i] < profits[j]) {
                // Swap the i-th and j-th jobs
                temp_deadline = deadlines[i];
                deadlines[i] = deadlines[j];
                deadlines[j] = temp_deadline;
                temp_profit = profits[i];
                profits[i] = profits[j];
                profits[j] = temp_profit;
            }
        }
    }
}

// Function to find the maximum deadline among all jobs
int find_max_deadline(int deadlines[], int n) {
    int i, max_deadline = deadlines[0];
    for (i = 1; i < n; i++) {
        if (deadlines[i] > max_deadline) {
            max_deadline = deadlines[i];
        }
    }
    return max_deadline;
}

// Function to solve the job scheduling problem with deadlines and profits
void job_scheduling(int deadlines[], int profits[], int n) {
    // Step 1: Sort the jobs in decreasing order of their profits
    sort_jobs_by_profit(deadlines, profits, n);

    // Step 2: Initialize an array of size equal to the maximum deadline among all jobs
    //         initially filled with zeros
    int max_deadline = find_max_deadline(deadlines, n);
    int *schedule = (int *) malloc((max_deadline+1) * sizeof(int));
    int i;
    for (i = 0; i <= max_deadline; i++) {
        schedule[i] = 0;
    }

    // Step 3: For each job in the sorted list, assign the job to the earliest available
    //         slot in the array starting from its deadline
    int total_profit = 0;
    int *assigned_jobs = (int *) malloc(n * sizeof(int));
    int num_assigned_jobs = 0;
    for (i = 0; i < n; i++) {
        int deadline = deadlines[i];
        int profit = profits[i];
        int j;
        for (j = deadline; j >= 1; j--) {
            if (schedule[j] == 0) {
                schedule[j] = 1;
                assigned_jobs[num_assigned_jobs] = i;
                num_assigned_jobs++;
                total_profit += profit;
                break;
            }
        }
    }

    // Step 4: Print the total profit earned and the indices of the jobs assigned
    printf("Total profit: %d\n", total_profit);
    printf("Assigned jobs: ");
    for (i = 0; i < num_assigned_jobs; i++) {
        printf("%d ", assigned_jobs[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(schedule);
    free(assigned_jobs);
}

int main() {
    // Example usage
    int deadlines[] = {3, 1, 2, 1};
    int profits[] = {20, 10, 15, 5};
    int n = 4;

    job_scheduling(deadlines, profits, n);

    return 0;
}
