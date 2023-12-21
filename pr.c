#include <stdio.h>

// Function to find waiting time, turnaround time, average wait time, and average turnaround time
void priorityScheduling(int processes[], int n, int bt[], int priority[]) {
    // Sort processes based on priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                // Swap priority
                int temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                // Swap processes
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;

                // Swap burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    int wt[n], tat[n];
    wt[0] = 0;

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    // Calculate average waiting time and average turnaround time
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];

        // Print individual waiting time and turnaround time
        printf("Process %d - Burst Time: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], priority[n];

    printf("Enter burst times and priorities for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Priority for process %d: ", i + 1);
        scanf("%d", &priority[i]);
        processes[i] = i + 1;
    }

    priorityScheduling(processes, n, burst_time, priority);

    return 0;
}
